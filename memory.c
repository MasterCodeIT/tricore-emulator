#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>

static uint8_t *pmu0 = NULL;
static uint8_t *pmu1 = NULL;

void set_memory_uint8_t(uint32_t address, uint8_t value) {
  printf("set_memory_uint8_t: %08x %02x\n", address, value);
  bool valid_80000000_range = address >= 0x80000000 && address <= 0x8fffffff;
  bool valid_d0000000_range = address >= 0xd0000000 && address <= 0xdfffffff;
  if (!valid_80000000_range && !valid_d0000000_range) {
    fprintf(stderr, "set_memory_uint8_t: TODO: %08x\n", address);
    exit(1);
  }
}

void set_memory_uint16_t(uint32_t address, uint16_t value) {
  printf("set_memory_uint16_t: %08x %04x\n", address, value);
  bool valid_80000000_range = address >= 0x80000000 && address <= 0x8fffffff;
  bool valid_d0000000_range = address >= 0xd0000000 && address <= 0xdfffffff;
  if (!valid_80000000_range && !valid_d0000000_range) {
    fprintf(stderr, "set_memory_uint16_t: TODO: %08x\n", address);
    exit(1);
  }
}

void set_memory_uint32_t(uint32_t address, uint32_t value) {
  printf("set_memory_uint32_t: %08x %08x\n", address, value);
  bool valid_80000000_range = address >= 0x80000000 && address <= 0x8fffffff;
  bool valid_d0000000_range = address >= 0xd0000000 && address <= 0xdfffffff;
  if (!valid_80000000_range && !valid_d0000000_range) {
    fprintf(stderr, "set_memory_uint32_t: TODO: %08x\n", address);
    exit(1);
  }
}

uint8_t get_memory_uint8_t(uint32_t address) {
  printf("get_memory_uint8_t %08x\n", address);
  if (address >= 0x80000000 && address <= 0x801FFFFF) {
    uint32_t offset = address - 0x80000000;
    return pmu0[offset];
  } else {
    fprintf(stderr, "get_memory_uint8_t: TODO: %08x\n", address);
    exit(1);
  }
}

uint16_t get_memory_uint16_t(uint32_t address) {
  printf("get_memory_uint16_t %08x\n", address);
  if (address >= 0x80000000 && address <= 0x801FFFFF) {
    uint32_t offset = address - 0x80000000;
    return (pmu0[offset + 1] << 8) + pmu0[offset];
  } else {
    fprintf(stderr, "get_memory_uint16_t: TODO: %08x\n", address);
    exit(1);
  }
}

uint32_t get_memory_uint32_t(uint32_t address) {
  fprintf(stderr, "get_memory_uint32_t: %08x\n", address);
  if (address >= 0x80000000 && address <= 0x801FFFFF) {
    uint32_t offset = address - 0x80000000;
    return (pmu0[offset + 3] << 24) + (pmu0[offset + 2] << 16) +
           (pmu0[offset + 1] << 8) + pmu0[offset];
  } else {
    fprintf(stderr, "get_memory_uint32_t: TODO: %08x\n", address);
    exit(1);
  }
}

void init_memory() {
  int pmu0_fd;
  int pmu1_fd;
  struct stat pmu0_s;
  struct stat pmu1_s;
  pmu0_fd = open("firmware.bin", O_RDONLY);
  pmu1_fd = open("pmu1.bin", O_RDONLY);
  fstat(pmu0_fd, &pmu0_s);
  fstat(pmu1_fd, &pmu1_s);
  pmu0 = mmap(0, pmu0_s.st_size, PROT_READ, MAP_PRIVATE, pmu0_fd, 0);
  pmu1 = mmap(0, pmu1_s.st_size, PROT_READ, MAP_PRIVATE, pmu1_fd, 0);
}
