// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "JSystem/JAudio/System/JASBank.h"
#include "JSystem/JAudio/System/JASDrumSet.h"
#include "JSystem/JAudio/System/JASCalc.h"

class JASBNKParser {
public:
    static void* createBank(const void*, JKRHeap*);
};

extern JKRHeap* JASDram;
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
void* JASBNKParser::createBank(const void* data, JKRHeap* heap) {
    return fn_8002F294(data, heap);
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

extern "C" void* fn_8002F34C(const void* data, JKRHeap* heap) {
    if (heap == 0) {
        heap = JASDram;
    }
    JASBasicBank* bank = new (heap, 0) JASBasicBank;
    if (bank == 0) {
        return 0;
    }
    return bank;
}

extern "C" void* fn_8002FB90(const void* data, JKRHeap* heap) {
    if (heap == 0) {
        heap = JASDram;
    }
    char* base = (char*)data;
    JASBasicBank* bank = new (heap, 0) JASBasicBank;
    if (bank == 0) {
        return 0;
    }

    unsigned long* instOff = (unsigned long*)base;
    for (int i = 0; i < 0x80; i++, instOff++) {
        char* inst = fn_80030454(base, instOff[9]);
        if (inst != 0) {
            JASBasicInst* basicInst = new (heap, 0) JASBasicInst;
            basicInst->setVolume(*(f32*)(inst + 8));
            basicInst->setPitch(*(f32*)(inst + 0xc));

            int oscIndex = 0;
            unsigned long* oscOff = (unsigned long*)inst;
            for (int j = 0; j < 2; j++, oscOff++) {
                char* rec = fn_8003043C(base, oscOff[4]);
                if (rec != 0) {
                    JASOscillator::Data* osc = (JASOscillator::Data*)fn_8003026C(bank, base, rec);
                    if (osc != 0) {
                        basicInst->setOsc(oscIndex, osc);
                    } else {
                        osc = new (heap, 0) JASOscillator::Data;
                        osc->mTarget = (unsigned char)rec[0];
                        osc->_04 = *(f32*)(rec + 4);

                        char* table = fn_80030424(base, ((unsigned long*)rec)[2]);
                        if (table != 0) {
                            int size = ((int)fn_80030380((short*)table) - (int)table) / 6 * 6;
                            char* copy = new (heap, 0) char[size];
                            JASCalc::bcopy(table, copy, size);
                            osc->mTable = (JASOscillator::Point*)copy;
                        } else {
                            osc->mTable = 0;
                        }

                        char* relTable = fn_80030424(base, ((unsigned long*)rec)[3]);
                        if (relTable != 0) {
                            int size = ((int)fn_80030380((short*)relTable) - (int)relTable) / 6 * 6;
                            char* copy = new (heap, 0) char[size];
                            JASCalc::bcopy(relTable, copy, size);
                            osc->rel_table = (JASOscillator::Point*)copy;
                        } else {
                            osc->rel_table = 0;
                        }

                        osc->mScale = *(f32*)(rec + 0x10);
                        osc->_14 = *(f32*)(rec + 0x14);
                        basicInst->setOsc(oscIndex, osc);
                    }
                    oscIndex++;
                }
            }

            unsigned long* randOff = (unsigned long*)inst;
            for (int j = 0; j < 2; j++, randOff++) {
                char* rec = fn_8003040C(base, randOff[6]);
                if (rec != 0) {
                    JASInstRand* rndEffect = new (heap, 0) JASInstRand;
                    rndEffect->setType((unsigned char)rec[0]);
                    rndEffect->set(*(f32*)(rec + 4), *(f32*)(rec + 8));
                    JASInstEffectLink* link = new (heap, 0) JASInstEffectLink(rndEffect);
                    basicInst->appendEffect(link);
                }
            }

            unsigned long* senseOff = (unsigned long*)inst;
            for (int j = 0; j < 2; j++, senseOff++) {
                char* rec = fn_800303F4(base, senseOff[8]);
                if (rec != 0) {
                    JASInstSense* sense = new (heap, 0) JASInstSense;
                    sense->setType((unsigned char)rec[0]);
                    sense->setParams((unsigned char)rec[1], (unsigned char)rec[2], *(f32*)(rec + 4), *(f32*)(rec + 8));
                    JASInstEffectLink* link = new (heap, 0) JASInstEffectLink(sense);
                    basicInst->appendEffect(link);
                }
            }

            basicInst->setKeyRegionCount(*(unsigned long*)(inst + 0x28), heap);
            unsigned long* keyOff = (unsigned long*)inst;
            for (unsigned long k = 0; k < *(unsigned long*)(inst + 0x28); k++, keyOff++) {
                JASBasicInst::TKeymap* keymap = basicInst->getKeyRegion(k);
                char* velo = fn_800303DC(base, keyOff[11]);
                keymap->mHighKey = (unsigned char)velo[0];
                keymap->setVeloRegionCount(*(unsigned long*)(velo + 4), heap);
                unsigned long* veloOff = (unsigned long*)velo;
                for (unsigned long j = 0; j < *(unsigned long*)(velo + 4); j++, veloOff++) {
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

    unsigned long* drumOff = (unsigned long*)base;
    for (int i = 0; i < 0xc; i++, drumOff++) {
        char* drum = fn_800303AC(base, drumOff[0xed]);
        if (drum != 0) {
            JASDrumSet* drumSet = new (heap, 0) JASDrumSet;
            unsigned long* percOff = (unsigned long*)(drum + 0x88);
            unsigned short* releaseOff = (unsigned short*)(drum + 0x308);
            for (int j = 0; j < 0x80; j++, percOff++, releaseOff++) {
                char* perc = fn_80030394(base, *percOff);
                if (perc != 0) {
                    JASDrumSet::TPerc* tperc = new (heap, 0) JASDrumSet::TPerc;
                    tperc->setVolume(*(f32*)perc);
                    tperc->setPitch(*(f32*)(perc + 4));
                    if (*(unsigned long*)drum == 0x50455232) {
                        tperc->setPan((f32)drum[0x288 + j] / 127.0f);
                        tperc->setRelease(*releaseOff);
                    }

                    unsigned long* percRand = (unsigned long*)perc;
                    for (int k = 0; k < 2; k++, percRand++) {
                        char* rec = fn_8003040C(base, percRand[2]);
                        if (rec != 0) {
                            JASInstRand* rndEffect = new (heap, 0) JASInstRand;
                            rndEffect->setType((unsigned char)rec[0]);
                            rndEffect->set(*(f32*)(rec + 4), *(f32*)(rec + 8));
                            JASInstEffectLink* link = new (heap, 0) JASInstEffectLink(rndEffect);
                            tperc->appendEffect(link);
                        }
                    }

                    tperc->setVeloRegionCount(((unsigned long*)perc)[4], heap);
                    unsigned long* veloOff = (unsigned long*)perc;
                    for (unsigned long k = 0; k < ((unsigned long*)perc)[4]; k++, veloOff++) {
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
            bank->setInst(0xe4 + i, drumSet);
        }
    }
    return bank;
}

extern "C" void* fn_8003026C(JASBasicBank* bank, char* data, char* key) {
    char* p;
    unsigned long* off = (unsigned long*)(data + 0x20);
    int i = 0;
    for (; i < 0x80; i++, off++) {
        p = fn_80030454(data, off[1]);
        if (p != 0) {
            for (int j = 0; j < 2; j++, p += 4) {
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

