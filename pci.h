#ifndef FAYT_PCI_H
#define FAYT_PCI_H_

#include <stdint.h>
#include <stddef.h>

struct [[gnu::packed]] pci_config_device {
	uint16_t vendor_id;
	uint16_t device_id;
	uint16_t command;
	uint16_t status;
	uint8_t revision_id;
	uint8_t prog_if;
	uint8_t subclass;
	uint8_t class;
	uint8_t cache_line_size;
	uint8_t reversed0;
	uint8_t header_type;
	uint8_t reserved1;
	uint32_t bar[6];
	uint32_t reserved2;
	uint16_t subsystem_vendor_id;
	uint16_t subsystem_device_id;
	uint32_t reserved3;
	uint8_t capabilities;
	uint8_t reserved4[3];
	uint8_t interrupt_line;
	uint8_t interrupt_pin;
	uint16_t reserved5;
};

struct [[gnu::packed]] pci_config_bridge {
	uint16_t vendor_id;
	uint16_t device_id;
	uint16_t command;
	uint16_t status;
	uint8_t revision_id;
	uint8_t prog_if;
	uint8_t subclass;
	uint8_t class;
	uint8_t cache_line_size;
	uint8_t latency_timer;
	uint8_t header_type;
	uint8_t bist;
	uint32_t bar[2];
	uint8_t primary_bus;
	uint8_t secondary_bus;
	uint8_t subordinate_bus;
	uint8_t secondary_latency_timer;
	uint8_t io_base;
	uint8_t io_limit;
	uint16_t secondary_status;
	uint16_t memory_base;
	uint16_t memory_limit;
	uint16_t prefetch_memory_base;
	uint16_t prefetch_memory_limit;
	uint32_t prefetch_upper_base32;
	uint32_t prefetch_upper_limit32;
	uint16_t io_base_upper16;
	uint16_t io_limit_upper;
	uint8_t capabilities;
	uint8_t reserved0[3];
	uint32_t expansion_rom_base;
	uint8_t interrupt_line;
	uint8_t interrupt_pin;
	uint16_t bridge_control;
};

union [[gnu::packed]] pci_config {
	struct pci_config_bridge device;
	struct pci_config_device bridge;
};

struct pci_bar {
	uint64_t base;
	uint64_t limit;
	bool is_mmio;
	bool is_prefetchable;
};

struct pci_descriptor {
	int segment;
	int bus;
	int device;
	int func;
};

struct pci_nbar {
	struct pci_descriptor descriptor;
	struct pci_bar bar;
	int bar_index;
	bool valid;
};

#endif
