// THIS FILE IS AUTOMATICALLY GENERATED
// from kernel/device/acpi.bits

// ACPI_PM1_STS

#define ACPI_PM1_STS_TMR_STS_BIT               0
#define ACPI_PM1_STS_BM_STS_BIT                4
#define ACPI_PM1_STS_GBL_STS_BIT               5
#define ACPI_PM1_STS_PWRBTN_STS_BIT            8
#define ACPI_PM1_STS_SLPBTN_STS_BIT            9
#define ACPI_PM1_STS_RTC_STS_BIT               10
#define ACPI_PM1_STS_PCIEXP_WAKE_STS_BIT       14
#define ACPI_PM1_STS_WAK_STS_BIT               15

#define ACPI_PM1_STS_TMR_STS_BITS              1
#define ACPI_PM1_STS_BM_STS_BITS               1
#define ACPI_PM1_STS_GBL_STS_BITS              1
#define ACPI_PM1_STS_PWRBTN_STS_BITS           1
#define ACPI_PM1_STS_SLPBTN_STS_BITS           1
#define ACPI_PM1_STS_RTC_STS_BITS              1
#define ACPI_PM1_STS_PCIEXP_WAKE_STS_BITS      1
#define ACPI_PM1_STS_WAK_STS_BITS              1
#define ACPI_PM1_STS_TMR_STS_MASK \
    ((1U << ACPI_PM1_STS_TMR_STS_BITS)-1)
#define ACPI_PM1_STS_BM_STS_MASK \
    ((1U << ACPI_PM1_STS_BM_STS_BITS)-1)
#define ACPI_PM1_STS_GBL_STS_MASK \
    ((1U << ACPI_PM1_STS_GBL_STS_BITS)-1)
#define ACPI_PM1_STS_PWRBTN_STS_MASK \
    ((1U << ACPI_PM1_STS_PWRBTN_STS_BITS)-1)
#define ACPI_PM1_STS_SLPBTN_STS_MASK \
    ((1U << ACPI_PM1_STS_SLPBTN_STS_BITS)-1)
#define ACPI_PM1_STS_RTC_STS_MASK \
    ((1U << ACPI_PM1_STS_RTC_STS_BITS)-1)
#define ACPI_PM1_STS_PCIEXP_WAKE_STS_MASK \
    ((1U << ACPI_PM1_STS_PCIEXP_WAKE_STS_BITS)-1)
#define ACPI_PM1_STS_WAK_STS_MASK \
    ((1U << ACPI_PM1_STS_WAK_STS_BITS)-1)

// (RW1C) Timer carry status bit (1=MSB of timer changed)
#define ACPI_PM1_STS_TMR_STS \
    (ACPI_PM1_STS_TMR_STS_MASK << ACPI_PM1_STS_TMR_STS_BIT)

// (RW1C) Bus master status bit (1=Bus master event occurred)
#define ACPI_PM1_STS_BM_STS \
    (ACPI_PM1_STS_BM_STS_MASK << ACPI_PM1_STS_BM_STS_BIT)

// BIOS raised IRQ after releasing global lock with pending bit set
#define ACPI_PM1_STS_GBL_STS \
    (ACPI_PM1_STS_GBL_STS_MASK << ACPI_PM1_STS_GBL_STS_BIT)

// (RW1C) Set when power button pressed and PWRBTN_EN is set
#define ACPI_PM1_STS_PWRBTN_STS \
    (ACPI_PM1_STS_PWRBTN_STS_MASK << ACPI_PM1_STS_PWRBTN_STS_BIT)

// (RW1C) Set when sleep button pressed and SLPBTN_EN is set
#define ACPI_PM1_STS_SLPBTN_STS \
    (ACPI_PM1_STS_SLPBTN_STS_MASK << ACPI_PM1_STS_SLPBTN_STS_BIT)

// (RW1C) Set when RTC generates alarm and RTC_EN is set
#define ACPI_PM1_STS_RTC_STS \
    (ACPI_PM1_STS_RTC_STS_MASK << ACPI_PM1_STS_RTC_STS_BIT)

// (RW1C) Set on PCI Express wake event
#define ACPI_PM1_STS_PCIEXP_WAKE_STS \
    (ACPI_PM1_STS_PCIEXP_WAKE_STS_MASK << ACPI_PM1_STS_PCIEXP_WAKE_STS_BIT)

// (RW1C) Set when sleeping and wake event occurs
#define ACPI_PM1_STS_WAK_STS \
    (ACPI_PM1_STS_WAK_STS_MASK << ACPI_PM1_STS_WAK_STS_BIT)

#define ACPI_PM1_STS_TMR_STS_n(n) \
    ((n) << ACPI_PM1_STS_TMR_STS_BIT)
#define ACPI_PM1_STS_BM_STS_n(n)               ((n) << ACPI_PM1_STS_BM_STS_BIT)
#define ACPI_PM1_STS_GBL_STS_n(n) \
    ((n) << ACPI_PM1_STS_GBL_STS_BIT)
#define ACPI_PM1_STS_PWRBTN_STS_n(n) \
    ((n) << ACPI_PM1_STS_PWRBTN_STS_BIT)
#define ACPI_PM1_STS_SLPBTN_STS_n(n) \
    ((n) << ACPI_PM1_STS_SLPBTN_STS_BIT)
#define ACPI_PM1_STS_RTC_STS_n(n) \
    ((n) << ACPI_PM1_STS_RTC_STS_BIT)
#define ACPI_PM1_STS_PCIEXP_WAKE_STS_n(n) \
    ((n) << ACPI_PM1_STS_PCIEXP_WAKE_STS_BIT)
#define ACPI_PM1_STS_WAK_STS_n(n) \
    ((n) << ACPI_PM1_STS_WAK_STS_BIT)

#define ACPI_PM1_STS_TMR_STS_GET(n) \
    (((n) >> ACPI_PM1_STS_TMR_STS_BIT) & ACPI_PM1_STS_TMR_STS_MASK)
#define ACPI_PM1_STS_BM_STS_GET(n) \
    (((n) >> ACPI_PM1_STS_BM_STS_BIT) & ACPI_PM1_STS_BM_STS_MASK)
#define ACPI_PM1_STS_GBL_STS_GET(n) \
    (((n) >> ACPI_PM1_STS_GBL_STS_BIT) & ACPI_PM1_STS_GBL_STS_MASK)
#define ACPI_PM1_STS_PWRBTN_STS_GET(n) \
    (((n) >> ACPI_PM1_STS_PWRBTN_STS_BIT) & ACPI_PM1_STS_PWRBTN_STS_MASK)
#define ACPI_PM1_STS_SLPBTN_STS_GET(n) \
    (((n) >> ACPI_PM1_STS_SLPBTN_STS_BIT) & ACPI_PM1_STS_SLPBTN_STS_MASK)
#define ACPI_PM1_STS_RTC_STS_GET(n) \
    (((n) >> ACPI_PM1_STS_RTC_STS_BIT) & ACPI_PM1_STS_RTC_STS_MASK)
#define ACPI_PM1_STS_PCIEXP_WAKE_STS_GET(n)    (((n) \
    >> ACPI_PM1_STS_PCIEXP_WAKE_STS_BIT) & ACPI_PM1_STS_PCIEXP_WAKE_STS_MASK)
#define ACPI_PM1_STS_WAK_STS_GET(n) \
    (((n) >> ACPI_PM1_STS_WAK_STS_BIT) & ACPI_PM1_STS_WAK_STS_MASK)

#define ACPI_PM1_STS_TMR_STS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_STS_TMR_STS) | ACPI_PM1_STS_TMR_STS_n((n)))
#define ACPI_PM1_STS_BM_STS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_STS_BM_STS) | ACPI_PM1_STS_BM_STS_n((n)))
#define ACPI_PM1_STS_GBL_STS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_STS_GBL_STS) | ACPI_PM1_STS_GBL_STS_n((n)))
#define ACPI_PM1_STS_PWRBTN_STS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_STS_PWRBTN_STS) | ACPI_PM1_STS_PWRBTN_STS_n((n)))
#define ACPI_PM1_STS_SLPBTN_STS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_STS_SLPBTN_STS) | ACPI_PM1_STS_SLPBTN_STS_n((n)))
#define ACPI_PM1_STS_RTC_STS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_STS_RTC_STS) | ACPI_PM1_STS_RTC_STS_n((n)))
#define ACPI_PM1_STS_PCIEXP_WAKE_STS_SET(r,n)  ((r) = ((r) \
    & ~ACPI_PM1_STS_PCIEXP_WAKE_STS) | ACPI_PM1_STS_PCIEXP_WAKE_STS_n((n)))
#define ACPI_PM1_STS_WAK_STS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_STS_WAK_STS) | ACPI_PM1_STS_WAK_STS_n((n)))

// ACPI_PM1_EVT

#define ACPI_PM1_EVT_TMR_EN_BIT                0
#define ACPI_PM1_EVT_GBL_EN_BIT                5
#define ACPI_PM1_EVT_PWRBTN_EN_BIT             8
#define ACPI_PM1_EVT_SLPBTN_EN_BIT             9
#define ACPI_PM1_EVT_RTC_EN_BIT                10
#define ACPI_PM1_EVT_PCIEXP_WAKE_DIS_BIT       14

#define ACPI_PM1_EVT_TMR_EN_BITS               1
#define ACPI_PM1_EVT_GBL_EN_BITS               1
#define ACPI_PM1_EVT_PWRBTN_EN_BITS            1
#define ACPI_PM1_EVT_SLPBTN_EN_BITS            1
#define ACPI_PM1_EVT_RTC_EN_BITS               1
#define ACPI_PM1_EVT_PCIEXP_WAKE_DIS_BITS      1
#define ACPI_PM1_EVT_TMR_EN_MASK \
    ((1U << ACPI_PM1_EVT_TMR_EN_BITS)-1)
#define ACPI_PM1_EVT_GBL_EN_MASK \
    ((1U << ACPI_PM1_EVT_GBL_EN_BITS)-1)
#define ACPI_PM1_EVT_PWRBTN_EN_MASK \
    ((1U << ACPI_PM1_EVT_PWRBTN_EN_BITS)-1)
#define ACPI_PM1_EVT_SLPBTN_EN_MASK \
    ((1U << ACPI_PM1_EVT_SLPBTN_EN_BITS)-1)
#define ACPI_PM1_EVT_RTC_EN_MASK \
    ((1U << ACPI_PM1_EVT_RTC_EN_BITS)-1)
#define ACPI_PM1_EVT_PCIEXP_WAKE_DIS_MASK \
    ((1U << ACPI_PM1_EVT_PCIEXP_WAKE_DIS_BITS)-1)

// Timer carry interrupt enable
#define ACPI_PM1_EVT_TMR_EN \
    (ACPI_PM1_EVT_TMR_EN_MASK << ACPI_PM1_EVT_TMR_EN_BIT)

// Global enable
#define ACPI_PM1_EVT_GBL_EN \
    (ACPI_PM1_EVT_GBL_EN_MASK << ACPI_PM1_EVT_GBL_EN_BIT)

// Power button enable
#define ACPI_PM1_EVT_PWRBTN_EN \
    (ACPI_PM1_EVT_PWRBTN_EN_MASK << ACPI_PM1_EVT_PWRBTN_EN_BIT)

// Sleep button enable
#define ACPI_PM1_EVT_SLPBTN_EN \
    (ACPI_PM1_EVT_SLPBTN_EN_MASK << ACPI_PM1_EVT_SLPBTN_EN_BIT)

// RTC wake enable
#define ACPI_PM1_EVT_RTC_EN \
    (ACPI_PM1_EVT_RTC_EN_MASK << ACPI_PM1_EVT_RTC_EN_BIT)

// PCI wake disable
#define ACPI_PM1_EVT_PCIEXP_WAKE_DIS \
    (ACPI_PM1_EVT_PCIEXP_WAKE_DIS_MASK << ACPI_PM1_EVT_PCIEXP_WAKE_DIS_BIT)

#define ACPI_PM1_EVT_TMR_EN_n(n)               ((n) << ACPI_PM1_EVT_TMR_EN_BIT)
#define ACPI_PM1_EVT_GBL_EN_n(n)               ((n) << ACPI_PM1_EVT_GBL_EN_BIT)
#define ACPI_PM1_EVT_PWRBTN_EN_n(n) \
    ((n) << ACPI_PM1_EVT_PWRBTN_EN_BIT)
#define ACPI_PM1_EVT_SLPBTN_EN_n(n) \
    ((n) << ACPI_PM1_EVT_SLPBTN_EN_BIT)
#define ACPI_PM1_EVT_RTC_EN_n(n)               ((n) << ACPI_PM1_EVT_RTC_EN_BIT)
#define ACPI_PM1_EVT_PCIEXP_WAKE_DIS_n(n) \
    ((n) << ACPI_PM1_EVT_PCIEXP_WAKE_DIS_BIT)

#define ACPI_PM1_EVT_TMR_EN_GET(n) \
    (((n) >> ACPI_PM1_EVT_TMR_EN_BIT) & ACPI_PM1_EVT_TMR_EN_MASK)
#define ACPI_PM1_EVT_GBL_EN_GET(n) \
    (((n) >> ACPI_PM1_EVT_GBL_EN_BIT) & ACPI_PM1_EVT_GBL_EN_MASK)
#define ACPI_PM1_EVT_PWRBTN_EN_GET(n) \
    (((n) >> ACPI_PM1_EVT_PWRBTN_EN_BIT) & ACPI_PM1_EVT_PWRBTN_EN_MASK)
#define ACPI_PM1_EVT_SLPBTN_EN_GET(n) \
    (((n) >> ACPI_PM1_EVT_SLPBTN_EN_BIT) & ACPI_PM1_EVT_SLPBTN_EN_MASK)
#define ACPI_PM1_EVT_RTC_EN_GET(n) \
    (((n) >> ACPI_PM1_EVT_RTC_EN_BIT) & ACPI_PM1_EVT_RTC_EN_MASK)
#define ACPI_PM1_EVT_PCIEXP_WAKE_DIS_GET(n)    (((n) \
    >> ACPI_PM1_EVT_PCIEXP_WAKE_DIS_BIT) & ACPI_PM1_EVT_PCIEXP_WAKE_DIS_MASK)

#define ACPI_PM1_EVT_TMR_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_EVT_TMR_EN) | ACPI_PM1_EVT_TMR_EN_n((n)))
#define ACPI_PM1_EVT_GBL_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_EVT_GBL_EN) | ACPI_PM1_EVT_GBL_EN_n((n)))
#define ACPI_PM1_EVT_PWRBTN_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_EVT_PWRBTN_EN) | ACPI_PM1_EVT_PWRBTN_EN_n((n)))
#define ACPI_PM1_EVT_SLPBTN_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_EVT_SLPBTN_EN) | ACPI_PM1_EVT_SLPBTN_EN_n((n)))
#define ACPI_PM1_EVT_RTC_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_EVT_RTC_EN) | ACPI_PM1_EVT_RTC_EN_n((n)))
#define ACPI_PM1_EVT_PCIEXP_WAKE_DIS_SET(r,n)  ((r) = ((r) \
    & ~ACPI_PM1_EVT_PCIEXP_WAKE_DIS) | ACPI_PM1_EVT_PCIEXP_WAKE_DIS_n((n)))

// ACPI_PM1_CTL

#define ACPI_PM1_CTL_SCI_EN_BIT        0
#define ACPI_PM1_CTL_BM_RLD_BIT        1
#define ACPI_PM1_CTL_GBL_RLS_BIT       2
#define ACPI_PM1_CTL_SLP_TYP_BIT       10
#define ACPI_PM1_CTL_SLP_EN_BIT        13

#define ACPI_PM1_CTL_SCI_EN_BITS       1
#define ACPI_PM1_CTL_BM_RLD_BITS       1
#define ACPI_PM1_CTL_GBL_RLS_BITS      1
#define ACPI_PM1_CTL_SLP_TYP_BITS      3
#define ACPI_PM1_CTL_SLP_EN_BITS       1
#define ACPI_PM1_CTL_SCI_EN_MASK       ((1U << ACPI_PM1_CTL_SCI_EN_BITS)-1)
#define ACPI_PM1_CTL_BM_RLD_MASK       ((1U << ACPI_PM1_CTL_BM_RLD_BITS)-1)
#define ACPI_PM1_CTL_GBL_RLS_MASK      ((1U << ACPI_PM1_CTL_GBL_RLS_BITS)-1)
#define ACPI_PM1_CTL_SLP_TYP_MASK      ((1U << ACPI_PM1_CTL_SLP_TYP_BITS)-1)
#define ACPI_PM1_CTL_SLP_EN_MASK       ((1U << ACPI_PM1_CTL_SLP_EN_BITS)-1)

//  SCI IRQ enable (1=SCI, 0=SMI)
#define ACPI_PM1_CTL_SCI_EN \
    (ACPI_PM1_CTL_SCI_EN_MASK << ACPI_PM1_CTL_SCI_EN_BIT)

// Transition to C0 from C3 on bus master event
#define ACPI_PM1_CTL_BM_RLD \
    (ACPI_PM1_CTL_BM_RLD_MASK << ACPI_PM1_CTL_BM_RLD_BIT)

// (WO) Notify firmware global lock released
#define ACPI_PM1_CTL_GBL_RLS \
    (ACPI_PM1_CTL_GBL_RLS_MASK << ACPI_PM1_CTL_GBL_RLS_BIT)

// Sleep type
#define ACPI_PM1_CTL_SLP_TYP \
    (ACPI_PM1_CTL_SLP_TYP_MASK << ACPI_PM1_CTL_SLP_TYP_BIT)

// (WO) Enter sleeping state when set
#define ACPI_PM1_CTL_SLP_EN \
    (ACPI_PM1_CTL_SLP_EN_MASK << ACPI_PM1_CTL_SLP_EN_BIT)

#define ACPI_PM1_CTL_SCI_EN_n(n)       ((n) << ACPI_PM1_CTL_SCI_EN_BIT)
#define ACPI_PM1_CTL_BM_RLD_n(n)       ((n) << ACPI_PM1_CTL_BM_RLD_BIT)
#define ACPI_PM1_CTL_GBL_RLS_n(n)      ((n) << ACPI_PM1_CTL_GBL_RLS_BIT)
#define ACPI_PM1_CTL_SLP_TYP_n(n)      ((n) << ACPI_PM1_CTL_SLP_TYP_BIT)
#define ACPI_PM1_CTL_SLP_EN_n(n)       ((n) << ACPI_PM1_CTL_SLP_EN_BIT)

#define ACPI_PM1_CTL_SCI_EN_GET(n) \
    (((n) >> ACPI_PM1_CTL_SCI_EN_BIT) & ACPI_PM1_CTL_SCI_EN_MASK)
#define ACPI_PM1_CTL_BM_RLD_GET(n) \
    (((n) >> ACPI_PM1_CTL_BM_RLD_BIT) & ACPI_PM1_CTL_BM_RLD_MASK)
#define ACPI_PM1_CTL_GBL_RLS_GET(n) \
    (((n) >> ACPI_PM1_CTL_GBL_RLS_BIT) & ACPI_PM1_CTL_GBL_RLS_MASK)
#define ACPI_PM1_CTL_SLP_TYP_GET(n) \
    (((n) >> ACPI_PM1_CTL_SLP_TYP_BIT) & ACPI_PM1_CTL_SLP_TYP_MASK)
#define ACPI_PM1_CTL_SLP_EN_GET(n) \
    (((n) >> ACPI_PM1_CTL_SLP_EN_BIT) & ACPI_PM1_CTL_SLP_EN_MASK)

#define ACPI_PM1_CTL_SCI_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_CTL_SCI_EN) | ACPI_PM1_CTL_SCI_EN_n((n)))
#define ACPI_PM1_CTL_BM_RLD_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_CTL_BM_RLD) | ACPI_PM1_CTL_BM_RLD_n((n)))
#define ACPI_PM1_CTL_GBL_RLS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_CTL_GBL_RLS) | ACPI_PM1_CTL_GBL_RLS_n((n)))
#define ACPI_PM1_CTL_SLP_TYP_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_CTL_SLP_TYP) | ACPI_PM1_CTL_SLP_TYP_n((n)))
#define ACPI_PM1_CTL_SLP_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM1_CTL_SLP_EN) | ACPI_PM1_CTL_SLP_EN_n((n)))

// ACPI_PM_TMR

#define ACPI_PM_TMR_CNT_24_BIT       0
#define ACPI_PM_TMR_CNT_32_BIT       0

#define ACPI_PM_TMR_CNT_24_BITS      24
#define ACPI_PM_TMR_CNT_32_BITS      32
#define ACPI_PM_TMR_CNT_24_MASK      ((1U << ACPI_PM_TMR_CNT_24_BITS)-1)
#define ACPI_PM_TMR_CNT_32_MASK      ((1U << ACPI_PM_TMR_CNT_32_BITS)-1)

// 24 bit timer value
#define ACPI_PM_TMR_CNT_24 \
    (ACPI_PM_TMR_CNT_24_MASK << ACPI_PM_TMR_CNT_24_BIT)

// 32 bit timer value
#define ACPI_PM_TMR_CNT_32 \
    (ACPI_PM_TMR_CNT_32_MASK << ACPI_PM_TMR_CNT_32_BIT)

#define ACPI_PM_TMR_CNT_24_n(n)      ((n) << ACPI_PM_TMR_CNT_24_BIT)
#define ACPI_PM_TMR_CNT_32_n(n)      ((n) << ACPI_PM_TMR_CNT_32_BIT)

#define ACPI_PM_TMR_CNT_24_GET(n) \
    (((n) >> ACPI_PM_TMR_CNT_24_BIT) & ACPI_PM_TMR_CNT_24_MASK)
#define ACPI_PM_TMR_CNT_32_GET(n) \
    (((n) >> ACPI_PM_TMR_CNT_32_BIT) & ACPI_PM_TMR_CNT_32_MASK)

#define ACPI_PM_TMR_CNT_24_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM_TMR_CNT_24) | ACPI_PM_TMR_CNT_24_n((n)))
#define ACPI_PM_TMR_CNT_32_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM_TMR_CNT_32) | ACPI_PM_TMR_CNT_32_n((n)))

// ACPI_PM2_CTL

#define ACPI_PM2_CTL_ARB_DIS_BIT       0

#define ACPI_PM2_CTL_ARB_DIS_BITS      1
#define ACPI_PM2_CTL_ARB_DIS_MASK      ((1U << ACPI_PM2_CTL_ARB_DIS_BITS)-1)

// Disable arbiter (1=prevent bus master)
#define ACPI_PM2_CTL_ARB_DIS \
    (ACPI_PM2_CTL_ARB_DIS_MASK << ACPI_PM2_CTL_ARB_DIS_BIT)

#define ACPI_PM2_CTL_ARB_DIS_n(n)      ((n) << ACPI_PM2_CTL_ARB_DIS_BIT)

#define ACPI_PM2_CTL_ARB_DIS_GET(n) \
    (((n) >> ACPI_PM2_CTL_ARB_DIS_BIT) & ACPI_PM2_CTL_ARB_DIS_MASK)

#define ACPI_PM2_CTL_ARB_DIS_SET(r,n) \
    ((r) = ((r) & ~ACPI_PM2_CTL_ARB_DIS) | ACPI_PM2_CTL_ARB_DIS_n((n)))

// ACPI_P_CNT

#define ACPI_P_CNT_CLK_VAL1_BIT       0
#define ACPI_P_CNT_THT_EN_BIT         4
#define ACPI_P_CNT_CLK_VAL2_BIT       5

#define ACPI_P_CNT_CLK_VAL1_BITS      4
#define ACPI_P_CNT_THT_EN_BITS        1
#define ACPI_P_CNT_CLK_VAL2_BITS      27
#define ACPI_P_CNT_CLK_VAL1_MASK      ((1U << ACPI_P_CNT_CLK_VAL1_BITS)-1)
#define ACPI_P_CNT_THT_EN_MASK        ((1U << ACPI_P_CNT_THT_EN_BITS)-1)
#define ACPI_P_CNT_CLK_VAL2_MASK      ((1U << ACPI_P_CNT_CLK_VAL2_BITS)-1)

// DUTY_OFFSET and DUTY_WIDTH describe which bits are the value
#define ACPI_P_CNT_CLK_VAL1 \
    (ACPI_P_CNT_CLK_VAL1_MASK << ACPI_P_CNT_CLK_VAL1_BIT)

// Throttle enable (must be disabled when changing clock value)
#define ACPI_P_CNT_THT_EN \
    (ACPI_P_CNT_THT_EN_MASK << ACPI_P_CNT_THT_EN_BIT)

// DUTY_OFFSET and DUTY_WIDTH describe which bits are the value
#define ACPI_P_CNT_CLK_VAL2 \
    (ACPI_P_CNT_CLK_VAL2_MASK << ACPI_P_CNT_CLK_VAL2_BIT)

#define ACPI_P_CNT_CLK_VAL1_n(n)      ((n) << ACPI_P_CNT_CLK_VAL1_BIT)
#define ACPI_P_CNT_THT_EN_n(n)        ((n) << ACPI_P_CNT_THT_EN_BIT)
#define ACPI_P_CNT_CLK_VAL2_n(n)      ((n) << ACPI_P_CNT_CLK_VAL2_BIT)

#define ACPI_P_CNT_CLK_VAL1_GET(n) \
    (((n) >> ACPI_P_CNT_CLK_VAL1_BIT) & ACPI_P_CNT_CLK_VAL1_MASK)
#define ACPI_P_CNT_THT_EN_GET(n) \
    (((n) >> ACPI_P_CNT_THT_EN_BIT) & ACPI_P_CNT_THT_EN_MASK)
#define ACPI_P_CNT_CLK_VAL2_GET(n) \
    (((n) >> ACPI_P_CNT_CLK_VAL2_BIT) & ACPI_P_CNT_CLK_VAL2_MASK)

#define ACPI_P_CNT_CLK_VAL1_SET(r,n) \
    ((r) = ((r) & ~ACPI_P_CNT_CLK_VAL1) | ACPI_P_CNT_CLK_VAL1_n((n)))
#define ACPI_P_CNT_THT_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_P_CNT_THT_EN) | ACPI_P_CNT_THT_EN_n((n)))
#define ACPI_P_CNT_CLK_VAL2_SET(r,n) \
    ((r) = ((r) & ~ACPI_P_CNT_CLK_VAL2) | ACPI_P_CNT_CLK_VAL2_n((n)))

// ACPI_P_LVL2

#define ACPI_P_LVL2_P_LVL2_BIT       0

#define ACPI_P_LVL2_P_LVL2_BITS      8
#define ACPI_P_LVL2_P_LVL2_MASK      ((1U << ACPI_P_LVL2_P_LVL2_BITS)-1)

// Reading this register enters C2 power state
#define ACPI_P_LVL2_P_LVL2 \
    (ACPI_P_LVL2_P_LVL2_MASK << ACPI_P_LVL2_P_LVL2_BIT)

#define ACPI_P_LVL2_P_LVL2_n(n)      ((n) << ACPI_P_LVL2_P_LVL2_BIT)

#define ACPI_P_LVL2_P_LVL2_GET(n) \
    (((n) >> ACPI_P_LVL2_P_LVL2_BIT) & ACPI_P_LVL2_P_LVL2_MASK)

#define ACPI_P_LVL2_P_LVL2_SET(r,n) \
    ((r) = ((r) & ~ACPI_P_LVL2_P_LVL2) | ACPI_P_LVL2_P_LVL2_n((n)))

// ACPI_P_LVL3

#define ACPI_P_LVL3_P_LVL3_BIT       0

#define ACPI_P_LVL3_P_LVL3_BITS      8
#define ACPI_P_LVL3_P_LVL3_MASK      ((1U << ACPI_P_LVL3_P_LVL3_BITS)-1)

// Reading this register enters C3 power state
#define ACPI_P_LVL3_P_LVL3 \
    (ACPI_P_LVL3_P_LVL3_MASK << ACPI_P_LVL3_P_LVL3_BIT)

#define ACPI_P_LVL3_P_LVL3_n(n)      ((n) << ACPI_P_LVL3_P_LVL3_BIT)

#define ACPI_P_LVL3_P_LVL3_GET(n) \
    (((n) >> ACPI_P_LVL3_P_LVL3_BIT) & ACPI_P_LVL3_P_LVL3_MASK)

#define ACPI_P_LVL3_P_LVL3_SET(r,n) \
    ((r) = ((r) & ~ACPI_P_LVL3_P_LVL3) | ACPI_P_LVL3_P_LVL3_n((n)))

// ACPI_SLEEP_CTL

#define ACPI_SLEEP_CTL_SLP_TYP_BIT       2
#define ACPI_SLEEP_CTL_SLP_EN_BIT        5

#define ACPI_SLEEP_CTL_SLP_TYP_BITS      3
#define ACPI_SLEEP_CTL_SLP_EN_BITS       1
#define ACPI_SLEEP_CTL_SLP_TYP_MASK \
    ((1U << ACPI_SLEEP_CTL_SLP_TYP_BITS)-1)
#define ACPI_SLEEP_CTL_SLP_EN_MASK       ((1U << ACPI_SLEEP_CTL_SLP_EN_BITS)-1)

// Select sleep type to enter when SLP_EN is set
#define ACPI_SLEEP_CTL_SLP_TYP \
    (ACPI_SLEEP_CTL_SLP_TYP_MASK << ACPI_SLEEP_CTL_SLP_TYP_BIT)

// (WO) Enter sleep type specified in SLP_TYP
#define ACPI_SLEEP_CTL_SLP_EN \
    (ACPI_SLEEP_CTL_SLP_EN_MASK << ACPI_SLEEP_CTL_SLP_EN_BIT)

#define ACPI_SLEEP_CTL_SLP_TYP_n(n)      ((n) << ACPI_SLEEP_CTL_SLP_TYP_BIT)
#define ACPI_SLEEP_CTL_SLP_EN_n(n)       ((n) << ACPI_SLEEP_CTL_SLP_EN_BIT)

#define ACPI_SLEEP_CTL_SLP_TYP_GET(n) \
    (((n) >> ACPI_SLEEP_CTL_SLP_TYP_BIT) & ACPI_SLEEP_CTL_SLP_TYP_MASK)
#define ACPI_SLEEP_CTL_SLP_EN_GET(n) \
    (((n) >> ACPI_SLEEP_CTL_SLP_EN_BIT) & ACPI_SLEEP_CTL_SLP_EN_MASK)

#define ACPI_SLEEP_CTL_SLP_TYP_SET(r,n) \
    ((r) = ((r) & ~ACPI_SLEEP_CTL_SLP_TYP) | ACPI_SLEEP_CTL_SLP_TYP_n((n)))
#define ACPI_SLEEP_CTL_SLP_EN_SET(r,n) \
    ((r) = ((r) & ~ACPI_SLEEP_CTL_SLP_EN) | ACPI_SLEEP_CTL_SLP_EN_n((n)))

// ACPI_SLEEP_STS

#define ACPI_SLEEP_STS_WAK_STS_BIT       7

#define ACPI_SLEEP_STS_WAK_STS_BITS      1
#define ACPI_SLEEP_STS_WAK_STS_MASK \
    ((1U << ACPI_SLEEP_STS_WAK_STS_BITS)-1)

// Set when system wakes from sleep
#define ACPI_SLEEP_STS_WAK_STS \
    (ACPI_SLEEP_STS_WAK_STS_MASK << ACPI_SLEEP_STS_WAK_STS_BIT)

#define ACPI_SLEEP_STS_WAK_STS_n(n)      ((n) << ACPI_SLEEP_STS_WAK_STS_BIT)

#define ACPI_SLEEP_STS_WAK_STS_GET(n) \
    (((n) >> ACPI_SLEEP_STS_WAK_STS_BIT) & ACPI_SLEEP_STS_WAK_STS_MASK)

#define ACPI_SLEEP_STS_WAK_STS_SET(r,n) \
    ((r) = ((r) & ~ACPI_SLEEP_STS_WAK_STS) | ACPI_SLEEP_STS_WAK_STS_n((n)))

