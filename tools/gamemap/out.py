from load import *
import csv,bisect,re
info=pickle.load(open(W+'/info.pkl','rb'))
rows=pickle.load(open(W+'/tus.pkl','rb'))
addrs=[f['addr'] for f in info]
LIB=[
 (0x80003100,0x80003458,'SDK/Runtime','__start.c (init)','named __start/__init_*'),
 (0x80003458,0x8000540C,'TRK','__exception.s (gTRKInterruptVectorTable)','symbol gTRKInterruptVectorTable..End'),
 (0x8000540C,0x80005600,'Runtime','__mem.c + _rom_copy_info/_bss_init_info','memset/memcpy/__fill_mem'),
 (0x80021840,0x800276F0,'JAudio2/JAI (Interface)','JAIAudience..JAIAudible','MKDD order; "cannot new Se" @80023750 (JAISeMgr), "It cost %d steps" @8002585C (JAISound); 13 __sinit'),
 (0x800276F0,0x80039B80,'JAudio2/JAS (System)','JASCalc..JASTrack/JASTrackPort','"SFR-UPDATE/MONO-MIX/UPDATE-DAC" @80029A94-8002A958 (JASAiCtrl); "/AudioRes/Waves/" @80030EF8 (JASWaveArcLoader); "JASTrack dump" @80034CAC (JASSeqParser)'),
 (0x80039B80,0x8003A500,'JAudio2/Task (C)','dspproc.c dsptask.c osdsp.c osdsp_task.c','32-byte padded C fns; "Already inited prior DSP task" @8003A0A0'),
 (0x8003A500,0x8003F610,'JAudio2/JAU (Utility)','JAUAudioArcLoader..JAUSoundObject','bitset<> asserts @8003DDA4.. (JAUSectionHeap); 11 __sinit'),
 (0x8003F610,0x8003F724,'SDK/base','PPCArch.c','named'),
 (0x8003F724,0x8003F810,'SDK/db','db.c','named'),
 (0x8003F810,0x80046804,'SDK/os','OS*.c','OSInit refs "<< Dolphin SDK - OS"'),
 (0x80046804,0x80046898,'Runtime','__ppc_eabi_init (__init_user/_ExitProcess)','named'),
 (0x80046898,0x80047258,'SDK/mtx','mtx.c vec.c mtx44.c (paired-single)','ps-heavy, no names'),
 (0x80047258,0x8004B7DC,'SDK/dvd','dvdlow.c dvdfs.c dvd.c dvdqueue.c dvderror.c fstload.c','"dvdfs.c"/"dvd.c" strings; DVD version string'),
 (0x8004B7DC,0x8004D4A0,'SDK/vi','vi.c','VI version string ref @8004BD78'),
 (0x8004D4A0,0x8004F8C0,'SDK/pad','Pad.c Padclamp.c','PAD version ref @8004E5D4'),
 (0x8004F8C0,0x8004FF48,'SDK/ai','ai.c','AI version ref @8004F908'),
 (0x8004FF48,0x80051AE8,'SDK/ar','ar.c arq.c','AR/ARQ version refs'),
 (0x80051AE8,0x80052200,'SDK/dsp','dsp.c dsp_debug.c dsp_task.c','DSP version ref @80051D40'),
 (0x80052200,0x80058ABC,'SDK/card','CARD*.c','CARD version ref @80053128'),
 (0x80058ABC,0x80060B88,'SDK/gx','GX*.c','GXInit @80058ABC'),
 (0x80060B88,0x80066DE0,'TRK_MINNOW_DOLPHIN','MetroTRK','named TRK*/udp_cc/ddh_cc/gdev_cc/MWTRACE'),
 (0x80066DE0,0x80067AF4,'Runtime (PowerPC_EABI_Support)','__va_arg, global_destructor_chain, runtime.c, __init_cpp_exceptions','named'),
 (0x80067AF4,0x80070608,'MSL_C','alloc/ansi_files/printf/string/math...','GCN_Mem_Alloc.c string @80067AF4; exit/fwrite/printf named'),
 (0x80070608,0x80071204,'SDK/amcstubs+odenotstub+OdemuExi2','AmcExi2Stubs.c, odenotstub.c, DebuggerDriver.c','AMC_IsStub/Hu_IsStub'),
 (0x80071204,0x80073C20,'SDK/exi','EXIBios.c EXIUart.c','EXI version ref @80072E5C'),
 (0x80073C20,0x80075580,'SDK/si','SIBios.c SISamplingRate.c','SI version ref @800744B8'),
 (0x80075580,0x80077124,'SDK/gba','GBA.c GBAGetProcessStatus.c GBAJoyBoot.c GBARead.c GBAWrite.c GBAXfer.c GBAKey.c','"GBAKey.c", "// Coded by Kawasedo"'),
 (0x80077124,0x800790A8,'JSystem/JMessage (+JGadget?)','resource/data/control/processor','4CC MESG/MGCL @800773AC, DAT1/STR1 @80077538'),
 (0x800790A8,0x80086E2C,'JSystem/JKernel','JKRAram..JKRThread','JKR*.cpp strings; objdiff-matched MKDD JKRCompArchive/JKRDisposer/JKRDvd*/JKRFileLoader'),
 (0x80086E2C,0x8008770C,'JSystem/JSupport','JSUList JSUInputStream JSUMemoryStream JSUFileStream','matched JSUMemoryStream @8008735C, JSUFileStream @800874D0'),
 (0x8008770C,0x80093600,'JSystem/JUtility','JUTDirectPrint..JUTVideo/JUTXfb/JUTFader','JUTException strings @8008A324-8008C608, JUTFont/JUTNameTab/JUTPalette/JUTResFont/JUTResource/JUTTexture/JUTVideo matched'),
 (0x80093600,0x800AF584,'JSystem/J2DGraph','J2DPane J2DScreen J2DPicture J2DTextBox J2DWindow J2DPrint J2DAnmLoader J2DMaterial J2DMatBlock','4CC PIC1/TBX1/PAC3 @800971F8-8009E6DC, PAF1/TPT1/VAF1/VCF1 @800A5ACC (J2DAnmLoader), TV16..TVB1 @800AE16C (J2DMaterialFactory)'),
 (0x800AF584,0x800E3F1C,'JSystem/J3D (GraphBase/Animator/Loader)','J3DSys..J3DModelLoader..J3DMaterialFactory','DRT1/DRW1/EVP1/SHP1/TEX1/VTX1 @800CC2E8 (J3DModelLoader) & @800E2B80 (CalcSize), PAF1.. @800CF3E8 (J3DAnmLoader), PEFG/TV16/TGB4/PEED @800DD148-800DF454 (J3DMaterialFactory)'),
 (0x800E3F1C,0x800E413C,'JSystem/JMath','JMath.cpp (ps)','paired-single'),
 (0x800E413C,0x800E6540,'JSystem/JFramework','JFWSystem.cpp JFWDisplay.cpp','calls OSInit/DVDInit; "GP hang due to XF stall bug" @800E633C (JFWDisplay)'),
 (0x800E6540,0x800F37A8,'JSystem/JParticle','JPA*.cpp','ps-heavy; BSP1/ESP1/ETX1/SSA1/SSP1/TDB1 @800F3398 (JPAResourceLoader)'),
 (0x800F37A8,0x800F3C10,'unknown (JSystem tail or first game TU)','?','JUTTexture users + __sinit 800F39EC registering JAudio-typed statics'),
]
out=[]
for s,e,sub,tu,ev in LIB:
    n=bisect.bisect_left(addrs,e)-bisect.bisect_left(addrs,s)
    out.append(['%08X'%s,'%08X'%e,'%X'%(e-s),n,sub,tu,'',ev,''])
for r in rows:
    ev=r['reason']+('; ends with __sinit '+' '.join('%08X'%x for x in r['sinit']) if r['sinit'] else '')
    tu='actor '+'/'.join(r['ids']) if r['ids'] else ''
    out.append(['%08X'%r['start'],'%08X'%r['end'],'%X'%(r['end']-r['start']),r['nf'],'game',tu,' '.join(r['ids']),ev,' || '.join(x.replace('\n','\\n') for x in r['strings'])])
with open(W+'/../tu_boundaries.csv','w',newline='') as f:
    w=csv.writer(f); w.writerow(['start','end','size','n_funcs','subsystem','tu_guess','actor_ids','evidence','sample_strings']); w.writerows(out)
print(len(out))
