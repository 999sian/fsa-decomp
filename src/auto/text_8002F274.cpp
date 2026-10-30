// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "JSystem/JAudio/System/JASBank.h"
#include "JSystem/JAudio/System/JASDrumSet.h"
#include "JSystem/JAudio/System/JASCalc.h"

#include "JSystem/JAudio/System/JASBNKParser.h"

extern JKRHeap* JASDram;
static inline unsigned long BankAlign8002F34C(unsigned long address) { return (address + 3) & ~3; }
static inline unsigned long* BankChunk8002F34C(char* base, unsigned long tag) {
    char* end = base + *(unsigned long*)(base + 4);
    unsigned long* chunk = (unsigned long*)(base + 0x20);
    while ((char*)chunk < end) {
        if (*chunk == tag) return chunk;
        chunk = (unsigned long*)BankAlign8002F34C((unsigned long)(chunk + 2) + chunk[1]);
    }
    return 0;
}
static inline JASInstEffect* BankEffect8002F34C(char* fx, JKRHeap* heap) {
    JASInstEffect* effect;
    int tag = *(int*)fx;
    fx += 4;
    switch (tag) {
    case 0x52616e64: {
        JASInstRand* rnd = new (heap, 0) JASInstRand;
        rnd->setType((unsigned char)fx[0]);
        rnd->setFloor(*(f32*)(fx+4));
        rnd->setCeiling(*(f32*)(fx+8));
        effect = rnd;
        break;
    }
    case 0x53656e73: {
        JASInstSense* sense = new (heap, 0) JASInstSense;
        sense->setType((unsigned char)fx[0]);
        sense->setParams((unsigned char)fx[1], (unsigned char)fx[2], *(f32*)(fx+4), *(f32*)(fx+8));
        effect = sense;
        break;
    }
    default: effect = 0; break;
    }
    return effect;
}
extern "C" char* fn_80030454(char* base, unsigned long off);
extern "C" char* fn_8003043C(char* base, unsigned long off);
extern "C" char* fn_80030424(char* base, unsigned long off);
extern "C" char* fn_8003040C(char* base, unsigned long off);
extern "C" char* fn_800303F4(char* base, unsigned long off);
extern "C" char* fn_800303DC(char* base, unsigned long off);
extern "C" char* fn_800303C4(char* base, unsigned long off);
extern "C" char* fn_800303AC(char* base, unsigned long off);
extern "C" char* fn_80030394(char* base, unsigned long off);
extern "C" void* fn_8003026C(JASBasicBank* bank, char* data, char* key);
extern "C" short* fn_80030380(short* p);
extern "C" int lbl_80557688;
extern "C" void* fn_8002FB90(const void*, JKRHeap*);
extern "C" void* fn_8002F34C(const void*, JKRHeap*);
extern "C" void* fn_8002F294(const void* data, JKRHeap* heap);
JASBank* JASBNKParser::createBank(const void* data, JKRHeap* heap) {
    return (JASBank*)fn_8002F294(data, heap);
}

extern "C" void* fn_8002F294(const void* data, JKRHeap* heap) {
    if (heap == 0) {
        heap = JASDram;
    }
    int before = heap->getFreeSize();
    void* bank = 0;
    switch (*(int*)((char*)data + 0xc)) {
    case 0:
        bank = fn_8002FB90(data, heap);
        break;
    case 1:
        bank = fn_8002F34C(data, heap);
        break;
    }
    lbl_80557688 += before - heap->getFreeSize();
    return bank;
}

#pragma opt_common_subs off
extern "C" void* fn_8002F34C(const void* data, JKRHeap* heap) {
    char* base = (char*)data;
    if (heap == 0) {
        heap = JASDram;
    }
    JASBasicBank* bank = new (heap, 0) JASBasicBank;
    if (bank == 0) {
        return 0;
    }

    unsigned long* envt = BankChunk8002F34C(base, 0x454e5654);
    unsigned long* osct = BankChunk8002F34C(base, 0x4f534354);
    unsigned long* list = BankChunk8002F34C(base, 0x4c495354);

    char* copy = new (heap, 2) char[envt[1]];
    JASCalc::bcopy(envt + 2, copy, envt[1]);

    unsigned long count = osct[2];
    envt = osct + 3;
    JASOscillator::Data* oscs = (JASOscillator::Data*)new (heap, 0) char[count * 0x18];
    JASOscillator::Data* dst = oscs;
    for (unsigned long n = count; n != 0; n--) {
        dst->mTarget = *(unsigned char*)((char*)envt + 4);
        dst->_04 = *(f32*)((char*)envt + 8);
        dst->mScale = *(f32*)((char*)envt + 0x14);
        dst->_14 = *(f32*)((char*)envt + 0x18);
        dst->mTable = (JASOscillator::Point*)(copy + *(unsigned long*)((char*)envt + 0xc));
        dst->rel_table = (JASOscillator::Point*)(copy + *(unsigned long*)((char*)envt + 0x10));
        (char*)envt += 0x1c;
        dst++;
    }

    envt = list;
    unsigned int i = 0;
    while (i < list[2]) {
        unsigned long off = envt[3];
        if (off != 0) {
            unsigned long* p = (unsigned long*)(base + off);
            int tag = *p++;
            switch (tag) {
            case 0x496e7374: {
                JASBasicInst* inst = new (heap, 0) JASBasicInst;
                unsigned long oscCount = *p++;
                for (unsigned long j = 0; j < oscCount; j++) {
                    inst->setOsc(j, oscs + *p++);
                }

                unsigned long effCount = *p++;
                for (unsigned long j = 0; j < effCount; j++) {
                    char* rec = base + *p++;
                    long effectTag = *(int*)rec;
                    char* fx = rec + 4;
                    JASInstEffect* effect;
                    switch (effectTag) {
                    case 0x52616e64: {
                        JASInstRand* rnd = new (heap, 0) JASInstRand;
                        rnd->setType((unsigned char)fx[0]);
                        rnd->setFloor(*(f32*)(fx + 4));
                        rnd->setCeiling(*(f32*)(fx + 8));
                        effect = rnd;
                        break;
                    }
                    case 0x53656e73: {
                        JASInstSense* sense = new (heap, 0) JASInstSense;
                        sense->setType((unsigned char)fx[0]);
                        sense->setParams((unsigned char)fx[1], (unsigned char)fx[2], *(f32*)(fx + 4), *(f32*)(fx + 8));
                        effect = sense;
                        break;
                    }
                    default: effect = 0; break;
                    }
                    JASInstEffectLink* link = new (heap, 0) JASInstEffectLink(effect);
                    inst->appendEffect(link);
                }

                unsigned long keyCount = *p++;
                inst->setKeyRegionCount(keyCount, heap);
                for (unsigned long k = 0; k < keyCount; k++) {
                    JASBasicInst::TKeymap* km = inst->getKeyRegion(k);
                    km->mHighKey = *p >> 24;
                    unsigned long veloCount = p[1];
                    p += 2;
                    km->setVeloRegionCount(veloCount, heap);
                    for (unsigned long j = 0; j < veloCount; j++) {
                        JASVelo* v = km->getVeloRegion(j);
                        v->_0 = *(unsigned char*)p;
                        v->_4 = p[1] & 0xffff;
                        v->_8 = *(f32*)(p + 2);
                        v->_c = *(f32*)(p + 3);
                        p += 4;
                    }
                }
                inst->setVolume(*(f32*)p);
                inst->setPitch(*(f32*)(p + 1));
                bank->setInst(i, inst);
                break;
            }
            case 0x50657263: {
                JASDrumSet* drum = new (heap, 0) JASDrumSet;
                unsigned long percCount = *p++;
                for (unsigned long j = 0; j < percCount; j++) {
                    unsigned long percOff = *p++;
                    if (percOff == 0) {
                        continue;
                    }
                    JASDrumSet::TPerc* perc = new (heap, 0) JASDrumSet::TPerc;
                    char* rec = base + percOff + 4;
                    perc->setVolume(*(f32*)rec);
                    perc->setPitch(*(f32*)(rec + 4));
                    perc->setPan((f32)*(unsigned char*)(rec + 8) / 127.0f);
                    perc->setRelease(*(unsigned short*)(rec + 0xa));

                    unsigned long effCount = *(unsigned long*)(rec + 0xc);
                    unsigned long* effp = (unsigned long*)(rec + 0xc);
                    unsigned long effCountFromPointer = *effp++;
                    effCount = effCountFromPointer;
                    for (unsigned long k = 0; k < effCount; k++) {
                        char* erec = base + *effp++;
                        long effectTag = *(int*)erec;
                        char* fx = erec + 4;
                        JASInstEffect* effect;
                        switch (effectTag) {
                        case 0x52616e64: {
                            JASInstRand* rnd = new (heap, 0) JASInstRand;
                            rnd->setType((unsigned char)fx[0]);
                            rnd->setFloor(*(f32*)(fx + 4));
                            rnd->setCeiling(*(f32*)(fx + 8));
                            effect = rnd;
                            break;
                        }
                        case 0x53656e73: {
                            JASInstSense* sense = new (heap, 0) JASInstSense;
                            sense->setType((unsigned char)fx[0]);
                            sense->setParams((unsigned char)fx[1], (unsigned char)fx[2], *(f32*)(fx + 4), *(f32*)(fx + 8));
                            effect = sense;
                            break;
                        }
                        default: effect = 0; break;
                        }
                        JASInstEffectLink* link = new (heap, 0) JASInstEffectLink(effect);
                        perc->appendEffect(link);
                    }

                    unsigned long veloCount = *effp++;
                    perc->setVeloRegionCount(veloCount, heap);
                    for (unsigned long k = 0; k < veloCount; k++) {
                        JASVelo* v = perc->getVeloRegion(k);
                        v->_0 = *(unsigned char*)effp;
                        v->_4 = effp[1] & 0xffff;
                        v->_8 = *(f32*)(effp + 2);
                        v->_c = *(f32*)(effp + 3);
                        effp += 4;
                    }
                    drum->setPerc(j, perc);
                }
                bank->setInst(i, drum);
                break;
            }
            }
        }
        envt++;
        i++;
    }
    return bank;
}
#pragma opt_lifetimes off
extern "C" void* fn_8002FB90(const void* data, JKRHeap* heap) {
    if (heap == 0) {
        heap = JASDram;
    }
    char* base = (char*)data;
    const JASBNKParser::TInst* inst;
    JASBasicBank* bank = new (heap, 0) JASBasicBank;
    if (bank == 0) {
        return 0;
    }

    int i;
    unsigned long* instOff;
    for (i = 0, instOff = (unsigned long*)base; i < 0x80; i++, instOff++) {
        inst = (const JASBNKParser::TInst*)fn_80030454(base, instOff[9]);
        if (inst != 0) {
            JASBasicInst* basicInst = new (heap, 0) JASBasicInst;
            basicInst->setVolume(inst->volume);
            basicInst->setPitch(inst->pitch);

            JASBNKParser::TOsc* rec;
            char* table;
            JASOscillator::Data* osc;
            int oscIndex;
            unsigned long* oscOff;
            int j;
            oscIndex = 0;
            oscOff = (unsigned long*)inst;
            for (j = 0; j < 2; j++, oscOff++) {
                rec = (JASBNKParser::TOsc*)fn_8003043C(base, oscOff[4]);
                if (rec != 0) {
                    JASOscillator::Data* shared = (JASOscillator::Data*)fn_8003026C(bank, base, (char*)rec);
                    if (shared != 0) {
                        basicInst->setOsc(oscIndex, shared);
                    } else {
                        osc = new (heap, 0) JASOscillator::Data;
                        osc->mTarget = rec->target;
                        osc->_04 = rec->_4;

                        table = fn_80030424(base, ((unsigned long*)rec)[2]);
                        if (table != 0) {
                            int size = ((int)fn_80030380((short*)table) - (int)table) / 6 * 6;
                            char* copy = new (heap, 0) char[size];
                            JASCalc::bcopy(table, copy, size);
                            osc->mTable = (JASOscillator::Point*)copy;
                        } else {
                            osc->mTable = 0;
                        }

                        table = fn_80030424(base, ((unsigned long*)rec)[3]);
                        if (table != 0) {
                            int size = ((int)fn_80030380((short*)table) - (int)table) / 6 * 6;
                            char* copy = new (heap, 0) char[size];
                            JASCalc::bcopy(table, copy, size);
                            osc->rel_table = (JASOscillator::Point*)copy;
                        } else {
                            osc->rel_table = 0;
                        }

                        osc->mScale = rec->scale;
                        osc->_14 = rec->_14;
                        basicInst->setOsc(oscIndex, osc);
                    }
                    oscIndex++;
                }
            }

            unsigned long* randOff;
            int randIndex;
            for (randIndex = 0, randOff = (unsigned long*)inst; randIndex < 2; randIndex++, randOff++) {
                char* rec = fn_8003040C(base, randOff[6]);
                if (rec != 0) {
                    JASInstRand* rndEffect = new (heap, 0) JASInstRand;
                    rndEffect->setType((unsigned char)rec[0]);
                    rndEffect->setFloor(*(f32*)(rec + 4));
                    rndEffect->setCeiling(*(f32*)(rec + 8));
                    JASInstEffectLink* link = new (heap, 0) JASInstEffectLink(rndEffect);
                    basicInst->appendEffect(link);
                }
            }

            unsigned long* senseOff;
            int senseIndex;
            for (senseIndex = 0, senseOff = (unsigned long*)inst; senseIndex < 2; senseIndex++, senseOff++) {
                char* rec = fn_800303F4(base, senseOff[8]);
                if (rec != 0) {
                    JASInstSense* sense = new (heap, 0) JASInstSense;
                    sense->setType((unsigned char)rec[0]);
                    sense->setParams((unsigned char)rec[1], (unsigned char)rec[2], *(f32*)(rec + 4), *(f32*)(rec + 8));
                    JASInstEffectLink* link = new (heap, 0) JASInstEffectLink(sense);
                    basicInst->appendEffect(link);
                }
            }

            basicInst->setKeyRegionCount(inst->keyRegionCount, heap);
            char* velo;
            unsigned long* veloOff;
            unsigned long* keyOff;
            unsigned int k;
            JASBasicInst::TKeymap* keymap;
            keyOff = (unsigned long*)inst;
            for (k = 0; k < inst->keyRegionCount; keyOff++, k++) {
                keymap = basicInst->getKeyRegion(k);
                velo = fn_800303DC(base, keyOff[11]);
                keymap->mHighKey = (unsigned char)velo[0];
                keymap->setVeloRegionCount(*(unsigned long*)(velo + 4), heap);
                veloOff = (unsigned long*)velo;
                for (unsigned int j = 0; j < *(unsigned long*)(velo + 4); veloOff++, j++) {
                    JASVelo* dst = keymap->getVeloRegion(j);
                    char* src = fn_800303C4(base, veloOff[2]);
                    dst->_0 = (unsigned char)src[0];
                    dst->_4 = *(unsigned long*)(src + 4) & 0xffff;
                    dst->_8 = *(f32*)(src + 8);
                    dst->_c = *(f32*)(src + 0xc);
                }
            }
            bank->setInst(i, basicInst);
        }
    }

    unsigned long* drumOff;
    int drumIndex;
    for (drumIndex = 0, drumOff = (unsigned long*)base; drumIndex < 0xc; drumIndex++, drumOff++) {
        char* drum = fn_800303AC(base, drumOff[0xed]);
        if (drum != 0) {
            JASDrumSet* drumSet = new (heap, 0) JASDrumSet;
            unsigned long* percOff = (unsigned long*)drum;
            unsigned short* releaseOff = (unsigned short*)drum;
            for (int j = 0; j < 0x80; j++, percOff++, releaseOff++) {
                char* perc = fn_80030394(base, percOff[0x22]);
                if (perc != 0) {
                    JASDrumSet::TPerc* tperc = new (heap, 0) JASDrumSet::TPerc;
                    tperc->setVolume(*(f32*)perc);
                    tperc->setPitch(*(f32*)(perc + 4));
                    if (*(unsigned long*)drum == 0x50455232) {
                        tperc->setPan((f32)drum[0x288 + j] / 127.0f);
                        tperc->setRelease(releaseOff[0x184]);
                    }

                    unsigned long* percRand;
                    int randIndex;
                    for (randIndex = 0, percRand = (unsigned long*)perc; randIndex < 2; randIndex++, percRand++) {
                        char* rec = fn_8003040C(base, percRand[2]);
                        if (rec != 0) {
                            JASInstRand* rndEffect = new (heap, 0) JASInstRand;
                            rndEffect->setType((unsigned char)rec[0]);
                            rndEffect->setFloor(*(f32*)(rec + 4));
                    rndEffect->setCeiling(*(f32*)(rec + 8));
                            JASInstEffectLink* link = new (heap, 0) JASInstEffectLink(rndEffect);
                            tperc->appendEffect(link);
                        }
                    }

                    tperc->setVeloRegionCount(((unsigned long*)perc)[4], heap);
                    unsigned long* veloOff = (unsigned long*)perc;
                    for (unsigned int k = 0; k < ((unsigned long*)perc)[4]; veloOff++, k++) {
                        JASVelo* dst = tperc->getVeloRegion(k);
                        char* src = fn_800303C4(base, veloOff[5]);
                        dst->_0 = (unsigned char)src[0];
                        dst->_4 = *(unsigned long*)(src + 4) & 0xffff;
                        dst->_8 = *(f32*)(src + 8);
                        dst->_c = *(f32*)(src + 0xc);
                    }
                    drumSet->setPerc(j, tperc);
                }
            }
            bank->setInst(0xe4 + drumIndex, drumSet);
        }
    }
    return bank;
}
#pragma opt_lifetimes reset
extern "C" void* fn_8003026C(JASBasicBank* bank, char* data, char* key) {
    char* p;
    unsigned long* off = (unsigned long*)(data + 0x20);
    int i = 0;
    int j;
    for (; i < 0x80; i++, off++) {
        char* q = fn_80030454(data, off[1]);
        if (q != 0) {
            for (j = 0, p = q; j < 2; j++, p += 4) {
                if (fn_8003043C(data, *(unsigned long*)(p + 0x10)) == key) {
                    JASInst* inst = bank->getInst(i);
                    if (inst != 0) {
                        JASInstParam param;
                        inst->getParam(0x3c, 0x7f, &param);
                        if (j < param._20) {
                            return param._1c[j];
                        }
                    }
                }
            }
        }
    }
    return 0;
}

extern "C" short* fn_80030380(short* p) {
    short v;
    do {
        v = *p;
        p += 3;
    } while (v <= 10);
    return p;
}

extern "C" char* fn_80030394(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_800303AC(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_800303C4(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_800303DC(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_800303F4(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_8003040C(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_80030424(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_8003043C(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_80030454(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

