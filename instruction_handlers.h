#include "parson/parson.h"

void handle_add_instruction(JSON_Object *instruction);
void handle_addi_instruction(JSON_Object *instruction);
void handle_addih_instruction(JSON_Object *instruction);
void handle_addsca_instruction(JSON_Object *instruction);
void handle_and_instruction(JSON_Object *instruction);
void handle_andne_instruction(JSON_Object *instruction);
void handle_call_instruction(JSON_Object *instruction);
void handle_calla_instruction(JSON_Object *instruction);
void handle_calli_instruction(JSON_Object *instruction);
void handle_dsync_instruction(JSON_Object *instruction);
void handle_extru_instruction(JSON_Object *instruction);
void handle_isync_instruction(JSON_Object *instruction);
void handle_j_instruction(JSON_Object *instruction);
void handle_jeq_instruction(JSON_Object *instruction);
void handle_jge_instruction(JSON_Object *instruction);
void handle_jgeu_instruction(JSON_Object *instruction);
void handle_jltu_instruction(JSON_Object *instruction);
void handle_jne_instruction(JSON_Object *instruction);
void handle_jnz_instruction(JSON_Object *instruction);
void handle_jz_instruction(JSON_Object *instruction);
void handle_jza_instruction(JSON_Object *instruction);
void handle_jzt_instruction(JSON_Object *instruction);
void handle_lda_instruction(JSON_Object *instruction);
void handle_ldbu_instruction(JSON_Object *instruction);
void handle_ldhu_instruction(JSON_Object *instruction);
void handle_ldw_instruction(JSON_Object *instruction);
void handle_lea_instruction(JSON_Object *instruction);
void handle_loop_instruction(JSON_Object *instruction);
void handle_mfcr_instruction(JSON_Object *instruction);
void handle_mov_instruction(JSON_Object *instruction);
void handle_mova_instruction(JSON_Object *instruction);
void handle_movaa_instruction(JSON_Object *instruction);
void handle_movd_instruction(JSON_Object *instruction);
void handle_movu_instruction(JSON_Object *instruction);
void handle_movh_instruction(JSON_Object *instruction);
void handle_movha_instruction(JSON_Object *instruction);
void handle_mtcr_instruction(JSON_Object *instruction);
void handle_ne_instruction(JSON_Object *instruction);
void handle_nop_instruction(JSON_Object *instruction);
void handle_or_instruction(JSON_Object *instruction);
void handle_orne_instruction(JSON_Object *instruction);
void handle_ret_instruction(JSON_Object *instruction);
void handle_sel_instruction(JSON_Object *instruction);
void handle_sh_instruction(JSON_Object *instruction);
void handle_sha_instruction(JSON_Object *instruction);
void handle_sta_instruction(JSON_Object *instruction);
void handle_stb_instruction(JSON_Object *instruction);
void handle_stw_instruction(JSON_Object *instruction);
void handle_sub_instruction(JSON_Object *instruction);
void handle_suba_instruction(JSON_Object *instruction);