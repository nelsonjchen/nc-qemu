DEF_HELPER_FLAGS_4(cc_compute_all, TCG_CALL_NO_RWG_SE, tl, tl, tl, tl, int)
DEF_HELPER_FLAGS_4(cc_compute_c, TCG_CALL_NO_RWG_SE, tl, tl, tl, tl, int)

DEF_HELPER_3(write_eflags, void, env, tl, i32)
DEF_HELPER_1(read_eflags, tl, env)
DEF_HELPER_2(divb_AL, void, env, tl)
DEF_HELPER_2(idivb_AL, void, env, tl)
DEF_HELPER_2(divw_AX, void, env, tl)
DEF_HELPER_2(idivw_AX, void, env, tl)
DEF_HELPER_2(divl_EAX, void, env, tl)
DEF_HELPER_2(idivl_EAX, void, env, tl)
#ifdef TARGET_X86_64
DEF_HELPER_2(divq_EAX, void, env, tl)
DEF_HELPER_2(idivq_EAX, void, env, tl)
#endif
DEF_HELPER_FLAGS_2(cr4_testbit, TCG_CALL_NO_WG, void, env, i32)

DEF_HELPER_FLAGS_2(bndck, TCG_CALL_NO_WG, void, env, i32)
DEF_HELPER_FLAGS_3(bndldx32, TCG_CALL_NO_WG, i64, env, tl, tl)
DEF_HELPER_FLAGS_3(bndldx64, TCG_CALL_NO_WG, i64, env, tl, tl)
DEF_HELPER_FLAGS_5(bndstx32, TCG_CALL_NO_WG, void, env, tl, tl, i64, i64)
DEF_HELPER_FLAGS_5(bndstx64, TCG_CALL_NO_WG, void, env, tl, tl, i64, i64)
DEF_HELPER_1(bnd_jmp, void, env)

DEF_HELPER_2(aam, void, env, int)
DEF_HELPER_2(aad, void, env, int)
DEF_HELPER_1(aaa, void, env)
DEF_HELPER_1(aas, void, env)
DEF_HELPER_1(daa, void, env)
DEF_HELPER_1(das, void, env)

DEF_HELPER_2(lsl, tl, env, tl)
DEF_HELPER_2(lar, tl, env, tl)
DEF_HELPER_2(verr, void, env, tl)
DEF_HELPER_2(verw, void, env, tl)
DEF_HELPER_2(lldt, void, env, int)
DEF_HELPER_2(ltr, void, env, int)
DEF_HELPER_3(load_seg, void, env, int, int)
DEF_HELPER_4(ljmp_protected, void, env, int, tl, tl)
DEF_HELPER_5(lcall_real, void, env, int, tl, int, int)
DEF_HELPER_5(lcall_protected, void, env, int, tl, int, tl)
DEF_HELPER_2(iret_real, void, env, int)
DEF_HELPER_3(iret_protected, void, env, int, int)
DEF_HELPER_3(lret_protected, void, env, int, int)
DEF_HELPER_2(read_crN, tl, env, int)
DEF_HELPER_3(write_crN, void, env, int, tl)
DEF_HELPER_2(lmsw, void, env, tl)
DEF_HELPER_1(clts, void, env)
DEF_HELPER_FLAGS_3(set_dr, TCG_CALL_NO_WG, void, env, int, tl)
DEF_HELPER_FLAGS_2(get_dr, TCG_CALL_NO_WG, tl, env, int)
DEF_HELPER_2(invlpg, void, env, tl)

DEF_HELPER_1(sysenter, void, env)
DEF_HELPER_2(sysexit, void, env, int)
#ifdef TARGET_X86_64
DEF_HELPER_2(sysret, void, env, int)
#if defined(CONFIG_USER_ONLY)
DEF_HELPER_2(syscall, noreturn, env, int)
DEF_HELPER_1(vsyscall, noreturn, env)
#else
DEF_HELPER_2(syscall, void, env, int)
#endif
#endif
DEF_HELPER_2(hlt, noreturn, env, int)
DEF_HELPER_2(monitor, void, env, tl)
DEF_HELPER_2(mwait, noreturn, env, int)
DEF_HELPER_2(pause, noreturn, env, int)
DEF_HELPER_1(debug, noreturn, env)
DEF_HELPER_1(reset_rf, void, env)
DEF_HELPER_3(raise_interrupt, void, env, int, int)
DEF_HELPER_2(raise_exception, void, env, int)
DEF_HELPER_1(cli, void, env)
DEF_HELPER_1(sti, void, env)
DEF_HELPER_1(clac, void, env)
DEF_HELPER_1(stac, void, env)
DEF_HELPER_3(boundw, void, env, tl, int)
DEF_HELPER_3(boundl, void, env, tl, int)
DEF_HELPER_1(rsm, void, env)
DEF_HELPER_2(into, void, env, int)
DEF_HELPER_2(cmpxchg8b_unlocked, void, env, tl)
DEF_HELPER_2(cmpxchg8b, void, env, tl)
#ifdef TARGET_X86_64
DEF_HELPER_2(cmpxchg16b_unlocked, void, env, tl)
DEF_HELPER_2(cmpxchg16b, void, env, tl)
#endif
DEF_HELPER_1(single_step, noreturn, env)
DEF_HELPER_1(rechecking_single_step, void, env)
DEF_HELPER_1(cpuid, void, env)
DEF_HELPER_1(rdtsc, void, env)
DEF_HELPER_1(rdtscp, void, env)
DEF_HELPER_1(rdpmc, noreturn, env)
DEF_HELPER_1(rdmsr, void, env)
DEF_HELPER_1(wrmsr, void, env)

DEF_HELPER_2(check_iob, void, env, i32)
DEF_HELPER_2(check_iow, void, env, i32)
DEF_HELPER_2(check_iol, void, env, i32)
DEF_HELPER_3(outb, void, env, i32, i32)
DEF_HELPER_2(inb, tl, env, i32)
DEF_HELPER_3(outw, void, env, i32, i32)
DEF_HELPER_2(inw, tl, env, i32)
DEF_HELPER_3(outl, void, env, i32, i32)
DEF_HELPER_2(inl, tl, env, i32)
DEF_HELPER_FLAGS_4(bpt_io, TCG_CALL_NO_WG, void, env, i32, i32, tl)

DEF_HELPER_3(svm_check_intercept_param, void, env, i32, i64)
DEF_HELPER_4(svm_check_io, void, env, i32, i32, i32)
DEF_HELPER_3(vmrun, void, env, int, int)
DEF_HELPER_1(vmmcall, void, env)
DEF_HELPER_2(vmload, void, env, int)
DEF_HELPER_2(vmsave, void, env, int)
DEF_HELPER_1(stgi, void, env)
DEF_HELPER_1(clgi, void, env)
DEF_HELPER_1(skinit, noreturn, env)
DEF_HELPER_2(invlpga, void, env, int)

/* x86 FPU */

DEF_HELPER_2(flds_FT0, void, env, i32)
DEF_HELPER_2(fldl_FT0, void, env, i64)
DEF_HELPER_2(fildl_FT0, void, env, s32)
DEF_HELPER_2(flds_ST0, void, env, i32)
DEF_HELPER_2(fldl_ST0, void, env, i64)
DEF_HELPER_2(fildl_ST0, void, env, s32)
DEF_HELPER_2(fildll_ST0, void, env, s64)
DEF_HELPER_1(fsts_ST0, i32, env)
DEF_HELPER_1(fstl_ST0, i64, env)
DEF_HELPER_1(fist_ST0, s32, env)
DEF_HELPER_1(fistl_ST0, s32, env)
DEF_HELPER_1(fistll_ST0, s64, env)
DEF_HELPER_1(fistt_ST0, s32, env)
DEF_HELPER_1(fisttl_ST0, s32, env)
DEF_HELPER_1(fisttll_ST0, s64, env)
DEF_HELPER_2(fldt_ST0, void, env, tl)
DEF_HELPER_2(fstt_ST0, void, env, tl)
DEF_HELPER_1(fpush, void, env)
DEF_HELPER_1(fpop, void, env)
DEF_HELPER_1(fdecstp, void, env)
DEF_HELPER_1(fincstp, void, env)
DEF_HELPER_2(ffree_STN, void, env, int)
DEF_HELPER_1(fmov_ST0_FT0, void, env)
DEF_HELPER_2(fmov_FT0_STN, void, env, int)
DEF_HELPER_2(fmov_ST0_STN, void, env, int)
DEF_HELPER_2(fmov_STN_ST0, void, env, int)
DEF_HELPER_2(fxchg_ST0_STN, void, env, int)
DEF_HELPER_1(fcom_ST0_FT0, void, env)
DEF_HELPER_1(fucom_ST0_FT0, void, env)
DEF_HELPER_1(fcomi_ST0_FT0, void, env)
DEF_HELPER_1(fucomi_ST0_FT0, void, env)
DEF_HELPER_1(fadd_ST0_FT0, void, env)
DEF_HELPER_1(fmul_ST0_FT0, void, env)
DEF_HELPER_1(fsub_ST0_FT0, void, env)
DEF_HELPER_1(fsubr_ST0_FT0, void, env)
DEF_HELPER_1(fdiv_ST0_FT0, void, env)
DEF_HELPER_1(fdivr_ST0_FT0, void, env)
DEF_HELPER_2(fadd_STN_ST0, void, env, int)
DEF_HELPER_2(fmul_STN_ST0, void, env, int)
DEF_HELPER_2(fsub_STN_ST0, void, env, int)
DEF_HELPER_2(fsubr_STN_ST0, void, env, int)
DEF_HELPER_2(fdiv_STN_ST0, void, env, int)
DEF_HELPER_2(fdivr_STN_ST0, void, env, int)
DEF_HELPER_1(fchs_ST0, void, env)
DEF_HELPER_1(fabs_ST0, void, env)
DEF_HELPER_1(fxam_ST0, void, env)
DEF_HELPER_1(fld1_ST0, void, env)
DEF_HELPER_1(fldl2t_ST0, void, env)
DEF_HELPER_1(fldl2e_ST0, void, env)
DEF_HELPER_1(fldpi_ST0, void, env)
DEF_HELPER_1(fldlg2_ST0, void, env)
DEF_HELPER_1(fldln2_ST0, void, env)
DEF_HELPER_1(fldz_ST0, void, env)
DEF_HELPER_1(fldz_FT0, void, env)
DEF_HELPER_1(fnstsw, i32, env)
DEF_HELPER_1(fnstcw, i32, env)
DEF_HELPER_2(fldcw, void, env, i32)
DEF_HELPER_1(fclex, void, env)
DEF_HELPER_1(fwait, void, env)
DEF_HELPER_1(fninit, void, env)
DEF_HELPER_2(fbld_ST0, void, env, tl)
DEF_HELPER_2(fbst_ST0, void, env, tl)
DEF_HELPER_1(f2xm1, void, env)
DEF_HELPER_1(fyl2x, void, env)
DEF_HELPER_1(fptan, void, env)
DEF_HELPER_1(fpatan, void, env)
DEF_HELPER_1(fxtract, void, env)
DEF_HELPER_1(fprem1, void, env)
DEF_HELPER_1(fprem, void, env)
DEF_HELPER_1(fyl2xp1, void, env)
DEF_HELPER_1(fsqrt, void, env)
DEF_HELPER_1(fsincos, void, env)
DEF_HELPER_1(frndint, void, env)
DEF_HELPER_1(fscale, void, env)
DEF_HELPER_1(fsin, void, env)
DEF_HELPER_1(fcos, void, env)
DEF_HELPER_3(fstenv, void, env, tl, int)
DEF_HELPER_3(fldenv, void, env, tl, int)
DEF_HELPER_3(fsave, void, env, tl, int)
DEF_HELPER_3(frstor, void, env, tl, int)
DEF_HELPER_FLAGS_2(fxsave, TCG_CALL_NO_WG, void, env, tl)
DEF_HELPER_FLAGS_2(fxrstor, TCG_CALL_NO_WG, void, env, tl)
DEF_HELPER_FLAGS_3(xsave, TCG_CALL_NO_WG, void, env, tl, i64)
DEF_HELPER_FLAGS_3(xsaveopt, TCG_CALL_NO_WG, void, env, tl, i64)
DEF_HELPER_FLAGS_3(xrstor, TCG_CALL_NO_WG, void, env, tl, i64)
DEF_HELPER_FLAGS_2(xgetbv, TCG_CALL_NO_WG, i64, env, i32)
DEF_HELPER_FLAGS_3(xsetbv, TCG_CALL_NO_WG, void, env, i32, i64)
DEF_HELPER_FLAGS_2(rdpkru, TCG_CALL_NO_WG, i64, env, i32)
DEF_HELPER_FLAGS_3(wrpkru, TCG_CALL_NO_WG, void, env, i32, i64)

DEF_HELPER_FLAGS_2(pdep, TCG_CALL_NO_RWG_SE, tl, tl, tl)
DEF_HELPER_FLAGS_2(pext, TCG_CALL_NO_RWG_SE, tl, tl, tl)

/* MMX/SSE */

DEF_HELPER_2(ldmxcsr, void, env, i32)
DEF_HELPER_1(enter_mmx, void, env)
DEF_HELPER_1(emms, void, env)
DEF_HELPER_3(movq, void, env, ptr, ptr)

#define SHIFT 0
#include "ops_sse_header.h"
#define SHIFT 1
#include "ops_sse_header.h"

DEF_HELPER_3(rclb, tl, env, tl, tl)
DEF_HELPER_3(rclw, tl, env, tl, tl)
DEF_HELPER_3(rcll, tl, env, tl, tl)
DEF_HELPER_3(rcrb, tl, env, tl, tl)
DEF_HELPER_3(rcrw, tl, env, tl, tl)
DEF_HELPER_3(rcrl, tl, env, tl, tl)
#ifdef TARGET_X86_64
DEF_HELPER_3(rclq, tl, env, tl, tl)
DEF_HELPER_3(rcrq, tl, env, tl, tl)
#endif

DEF_HELPER_1(rdrand, tl, env)
