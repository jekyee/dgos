// THIS FILE IS AUTOMATICALLY GENERATED
// from kernel/net/ipv4.bits

// IPv4_VERLEN

#define IPv4_VERLEN_VER_BIT       0
#define IPv4_VERLEN_LEN_BIT       4

#define IPv4_VERLEN_VER_BITS      4
#define IPv4_VERLEN_LEN_BITS      4
#define IPv4_VERLEN_VER_MASK      ((1U << IPv4_VERLEN_VER_BITS)-1)
#define IPv4_VERLEN_LEN_MASK      ((1U << IPv4_VERLEN_LEN_BITS)-1)
#define IPv4_VERLEN_VER           (IPv4_VERLEN_VER_MASK << IPv4_VERLEN_VER_BIT)
#define IPv4_VERLEN_LEN           (IPv4_VERLEN_LEN_MASK << IPv4_VERLEN_LEN_BIT)

#define IPv4_VERLEN_VER_n(n)      ((n) << IPv4_VERLEN_VER_BIT)
#define IPv4_VERLEN_LEN_n(n)      ((n) << IPv4_VERLEN_LEN_BIT)

#define IPv4_VERLEN_VER_GET(n) \
    (((n) >> IPv4_VERLEN_VER_BIT) & IPv4_VERLEN_VER_MASK)
#define IPv4_VERLEN_LEN_GET(n) \
    (((n) >> IPv4_VERLEN_LEN_BIT) & IPv4_VERLEN_LEN_MASK)

#define IPv4_VERLEN_VER_SET(r,n) \
    ((r) = ((r) & ~IPv4_VERLEN_VER) | IPv4_VERLEN_VER_n((n)))
#define IPv4_VERLEN_LEN_SET(r,n) \
    ((r) = ((r) & ~IPv4_VERLEN_LEN) | IPv4_VERLEN_LEN_n((n)))

// IPv4_TOS

#define IPv4_TOS_PREC_BIT       0
#define IPv4_TOS_D_BIT          3
#define IPv4_TOS_T_BIT          4
#define IPv4_TOS_R_BIT          5
#define IPv4_TOS_RSVD_BIT       6

#define IPv4_TOS_PREC_BITS      3
#define IPv4_TOS_D_BITS         1
#define IPv4_TOS_T_BITS         1
#define IPv4_TOS_R_BITS         1
#define IPv4_TOS_RSVD_BITS      2
#define IPv4_TOS_PREC_MASK      ((1U << IPv4_TOS_PREC_BITS)-1)
#define IPv4_TOS_D_MASK         ((1U << IPv4_TOS_D_BITS)-1)
#define IPv4_TOS_T_MASK         ((1U << IPv4_TOS_T_BITS)-1)
#define IPv4_TOS_R_MASK         ((1U << IPv4_TOS_R_BITS)-1)
#define IPv4_TOS_RSVD_MASK      ((1U << IPv4_TOS_RSVD_BITS)-1)
#define IPv4_TOS_PREC           (IPv4_TOS_PREC_MASK << IPv4_TOS_PREC_BIT)

// Low delay
#define IPv4_TOS_D              (IPv4_TOS_D_MASK << IPv4_TOS_D_BIT)

// High throughput
#define IPv4_TOS_T              (IPv4_TOS_T_MASK << IPv4_TOS_T_BIT)

// High reliability
#define IPv4_TOS_R              (IPv4_TOS_R_MASK << IPv4_TOS_R_BIT)
#define IPv4_TOS_RSVD           (IPv4_TOS_RSVD_MASK << IPv4_TOS_RSVD_BIT)

#define IPv4_TOS_PREC_n(n)      ((n) << IPv4_TOS_PREC_BIT)
#define IPv4_TOS_D_n(n)         ((n) << IPv4_TOS_D_BIT)
#define IPv4_TOS_T_n(n)         ((n) << IPv4_TOS_T_BIT)
#define IPv4_TOS_R_n(n)         ((n) << IPv4_TOS_R_BIT)
#define IPv4_TOS_RSVD_n(n)      ((n) << IPv4_TOS_RSVD_BIT)

#define IPv4_TOS_PREC_GET(n) \
    (((n) >> IPv4_TOS_PREC_BIT) & IPv4_TOS_PREC_MASK)
#define IPv4_TOS_D_GET(n)       (((n) >> IPv4_TOS_D_BIT) & IPv4_TOS_D_MASK)
#define IPv4_TOS_T_GET(n)       (((n) >> IPv4_TOS_T_BIT) & IPv4_TOS_T_MASK)
#define IPv4_TOS_R_GET(n)       (((n) >> IPv4_TOS_R_BIT) & IPv4_TOS_R_MASK)
#define IPv4_TOS_RSVD_GET(n) \
    (((n) >> IPv4_TOS_RSVD_BIT) & IPv4_TOS_RSVD_MASK)

#define IPv4_TOS_PREC_SET(r,n) \
    ((r) = ((r) & ~IPv4_TOS_PREC) | IPv4_TOS_PREC_n((n)))
#define IPv4_TOS_D_SET(r,n)     ((r) = ((r) & ~IPv4_TOS_D) | IPv4_TOS_D_n((n)))
#define IPv4_TOS_T_SET(r,n)     ((r) = ((r) & ~IPv4_TOS_T) | IPv4_TOS_T_n((n)))
#define IPv4_TOS_R_SET(r,n)     ((r) = ((r) & ~IPv4_TOS_R) | IPv4_TOS_R_n((n)))
#define IPv4_TOS_RSVD_SET(r,n) \
    ((r) = ((r) & ~IPv4_TOS_RSVD) | IPv4_TOS_RSVD_n((n)))

// IPv4_TOS_PREC_NETCTL
#define IPv4_TOS_PREC_NETCTL 7

// IPv4_TOS_PREC_INETCTL
#define IPv4_TOS_PREC_INETCTL 6

// IPv4_TOS_PREC_ECP
#define IPv4_TOS_PREC_ECP 5

// IPv4_TOS_PREC_FLASHOVR
#define IPv4_TOS_PREC_FLASHOVR 4

// IPv4_TOS_PREC_FLASH
#define IPv4_TOS_PREC_FLASH 3

// IPv4_TOS_PREC_IMMEDIATE
#define IPv4_TOS_PREC_IMMEDIATE 2

// IPv4_TOS_PREC_PRIORITY
#define IPv4_TOS_PREC_PRIORITY 1

// IPv4_TOS_PREC_ROUTINE
#define IPv4_TOS_PREC_ROUTINE 0

