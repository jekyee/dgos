#pragma once

#include "types.h"
#include "physmem_data.h"
#include "paging.h"

bool get_ram_regions();

void take_pages(uint64_t phys_addr, uint64_t size);

// Allocate the first free range, and take up to the specified amount,
// or, take the entire first free block if it is smaller than size
phys_alloc_t alloc_phys(uint64_t size);

class alloc_page_factory_t : public page_factory_t {
public:
    phys_alloc_t alloc(size64_t size) noexcept override final
    {
        return alloc_phys(size);
    }
};
