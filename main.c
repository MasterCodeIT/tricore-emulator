#include "instruction_handlers.h"
#include "log.h"
#include "memory.h"
#include "parson/parson.h"
#include "registers.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_instruction(JSON_Object *instruction) {
  const char *mnemonic;
  mnemonic = json_object_get_string(instruction, "mnemonic");
  if (strcmp(mnemonic, "add") == 0) {
    handle_add_instruction(instruction);
  } else if (strcmp(mnemonic, "addi") == 0) {
    handle_addi_instruction(instruction);
  } else if (strcmp(mnemonic, "addih") == 0) {
    handle_addih_instruction(instruction);
  } else if (strcmp(mnemonic, "addsc.a") == 0) {
    handle_addsca_instruction(instruction);
  } else if (strcmp(mnemonic, "and") == 0) {
    handle_and_instruction(instruction);
  } else if (strcmp(mnemonic, "and.ne") == 0) {
    handle_andne_instruction(instruction);
  } else if (strcmp(mnemonic, "call") == 0) {
    handle_call_instruction(instruction);
  } else if (strcmp(mnemonic, "calla") == 0) {
    handle_calla_instruction(instruction);
  } else if (strcmp(mnemonic, "calli") == 0) {
    handle_calli_instruction(instruction);
  } else if (strcmp(mnemonic, "dsync") == 0) {
    handle_dsync_instruction(instruction);
  } else if (strcmp(mnemonic, "extr.u") == 0) {
    handle_extru_instruction(instruction);
  } else if (strcmp(mnemonic, "insert") == 0) {
    handle_insert_instruction(instruction);
  } else if (strcmp(mnemonic, "isync") == 0) {
    handle_isync_instruction(instruction);
  } else if (strcmp(mnemonic, "j") == 0) {
    handle_j_instruction(instruction);
  } else if (strcmp(mnemonic, "jeq") == 0) {
    handle_jeq_instruction(instruction);
  } else if (strcmp(mnemonic, "jge") == 0) {
    handle_jge_instruction(instruction);
  } else if (strcmp(mnemonic, "jge.u") == 0) {
    handle_jgeu_instruction(instruction);
  } else if (strcmp(mnemonic, "jlt.u") == 0) {
    handle_jltu_instruction(instruction);
  } else if (strcmp(mnemonic, "jne") == 0) {
    handle_jne_instruction(instruction);
  } else if (strcmp(mnemonic, "jnz") == 0) {
    handle_jnz_instruction(instruction);
  } else if (strcmp(mnemonic, "jz") == 0) {
    handle_jz_instruction(instruction);
  } else if (strcmp(mnemonic, "jz.a") == 0) {
    handle_jza_instruction(instruction);
  } else if (strcmp(mnemonic, "jz.t") == 0) {
    handle_jzt_instruction(instruction);
  } else if (strcmp(mnemonic, "ld.a") == 0) {
    handle_lda_instruction(instruction);
  } else if (strcmp(mnemonic, "ld.b") == 0) {
    handle_ldb_instruction(instruction);
  } else if (strcmp(mnemonic, "ld.bu") == 0) {
    handle_ldbu_instruction(instruction);
  } else if (strcmp(mnemonic, "ld.hu") == 0) {
    handle_ldhu_instruction(instruction);
  } else if (strcmp(mnemonic, "ld.w") == 0) {
    handle_ldw_instruction(instruction);
  } else if (strcmp(mnemonic, "lea") == 0) {
    handle_lea_instruction(instruction);
  } else if (strcmp(mnemonic, "loop") == 0) {
    handle_loop_instruction(instruction);
  } else if (strcmp(mnemonic, "mfcr") == 0) {
    handle_mfcr_instruction(instruction);
  } else if (strcmp(mnemonic, "mov") == 0) {
    handle_mov_instruction(instruction);
  } else if (strcmp(mnemonic, "mov.a") == 0) {
    handle_mova_instruction(instruction);
  } else if (strcmp(mnemonic, "mov.aa") == 0) {
    handle_movaa_instruction(instruction);
  } else if (strcmp(mnemonic, "mov.d") == 0) {
    handle_movd_instruction(instruction);
  } else if (strcmp(mnemonic, "mov.u") == 0) {
    handle_movu_instruction(instruction);
  } else if (strcmp(mnemonic, "movh") == 0) {
    handle_movh_instruction(instruction);
  } else if (strcmp(mnemonic, "movh.a") == 0) {
    handle_movha_instruction(instruction);
  } else if (strcmp(mnemonic, "mtcr") == 0) {
    handle_mtcr_instruction(instruction);
  } else if (strcmp(mnemonic, "ne") == 0) {
    handle_ne_instruction(instruction);
  } else if (strcmp(mnemonic, "nop") == 0) {
    handle_nop_instruction(instruction);
  } else if (strcmp(mnemonic, "or") == 0) {
    handle_or_instruction(instruction);
  } else if (strcmp(mnemonic, "or.or.t") == 0) {
    handle_orort_instruction(instruction);
  } else if (strcmp(mnemonic, "or.ne") == 0) {
    handle_orne_instruction(instruction);
  } else if (strcmp(mnemonic, "ret") == 0) {
    handle_ret_instruction(instruction);
  } else if (strcmp(mnemonic, "sel") == 0) {
    handle_sel_instruction(instruction);
  } else if (strcmp(mnemonic, "sh") == 0) {
    handle_sh_instruction(instruction);
  } else if (strcmp(mnemonic, "sh") == 0) {
    handle_sh_instruction(instruction);
  } else if (strcmp(mnemonic, "sh.or.t") == 0) {
    handle_short_instruction(instruction);
  } else if (strcmp(mnemonic, "st.a") == 0) {
    handle_sta_instruction(instruction);
  } else if (strcmp(mnemonic, "st.b") == 0) {
    handle_stb_instruction(instruction);
  } else if (strcmp(mnemonic, "st.w") == 0) {
    handle_stw_instruction(instruction);
  } else if (strcmp(mnemonic, "sub") == 0) {
    handle_sub_instruction(instruction);
  } else if (strcmp(mnemonic, "sub.a") == 0) {
    handle_suba_instruction(instruction);
  } else if (strcmp(mnemonic, "xor") == 0) {
    handle_xor_instruction(instruction);
  } else {
    fprintf(stderr, "invalid mnemonic: %s\n", mnemonic);
    exit(1);
  }
}

int main(int argc, char *argv[]) {
  // declar variables
  JSON_Value *root_value;
  JSON_Object *instructions;
  JSON_Object *instruction;
  uint32_t program_counter;
  char formatted_address[9];
  char buf[16];
  bool debugger_tripped = 0;
  // read instructions
  root_value = json_parse_file("security-access-instructions-map.json");
  instructions = json_value_get_object(root_value);
  // kickoff execution
  init_memory();
  set_register("pc", 0xc0002bce); // use 0x80000238 for firmware debugging
  set_register("a4", 0xc0000000); // random scratchpad in memory
  uint32_t seed = 0xE572B95C;
  set_memory_uint32_t(0xc0000000, seed);
  debugger_tripped = 1;
  for (;;) {
    program_counter = get_register("pc");
    sprintf(formatted_address, "%08x", program_counter);
    instruction = json_object_get_object(instructions, formatted_address);
    if (instruction == NULL) {
      fprintf(stderr, "instruction not found at address %s\n",
              formatted_address);
      exit(1);
    }
    log_instruction(instruction);
    log_registers();
    handle_instruction(instruction);
    if (debugger_tripped) {
      gets(buf);
    }
  }
  json_value_free(root_value);
}
