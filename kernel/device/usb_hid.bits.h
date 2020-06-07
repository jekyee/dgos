// THIS FILE IS AUTOMATICALLY GENERATED
// from kernel/device/usb_hid.bits

// USBHID_REPORT_HEADER

#define USBHID_REPORT_HEADER_SIZE_BIT       0
#define USBHID_REPORT_HEADER_TYPE_BIT       2
#define USBHID_REPORT_HEADER_TAG_BIT        4

#define USBHID_REPORT_HEADER_SIZE_BITS      2
#define USBHID_REPORT_HEADER_TYPE_BITS      2
#define USBHID_REPORT_HEADER_TAG_BITS       4
#define USBHID_REPORT_HEADER_SIZE_MASK \
    ((1U << USBHID_REPORT_HEADER_SIZE_BITS)-1)
#define USBHID_REPORT_HEADER_TYPE_MASK \
    ((1U << USBHID_REPORT_HEADER_TYPE_BITS)-1)
#define USBHID_REPORT_HEADER_TAG_MASK \
    ((1U << USBHID_REPORT_HEADER_TAG_BITS)-1)
#define USBHID_REPORT_HEADER_SIZE \
    (USBHID_REPORT_HEADER_SIZE_MASK << USBHID_REPORT_HEADER_SIZE_BIT)
#define USBHID_REPORT_HEADER_TYPE \
    (USBHID_REPORT_HEADER_TYPE_MASK << USBHID_REPORT_HEADER_TYPE_BIT)
#define USBHID_REPORT_HEADER_TAG \
    (USBHID_REPORT_HEADER_TAG_MASK << USBHID_REPORT_HEADER_TAG_BIT)

#define USBHID_REPORT_HEADER_SIZE_n(n) \
    ((n) << USBHID_REPORT_HEADER_SIZE_BIT)
#define USBHID_REPORT_HEADER_TYPE_n(n) \
    ((n) << USBHID_REPORT_HEADER_TYPE_BIT)
#define USBHID_REPORT_HEADER_TAG_n(n) \
    ((n) << USBHID_REPORT_HEADER_TAG_BIT)

#define USBHID_REPORT_HEADER_SIZE_GET(n) \
    (((n) >> USBHID_REPORT_HEADER_SIZE_BIT) & USBHID_REPORT_HEADER_SIZE_MASK)
#define USBHID_REPORT_HEADER_TYPE_GET(n) \
    (((n) >> USBHID_REPORT_HEADER_TYPE_BIT) & USBHID_REPORT_HEADER_TYPE_MASK)
#define USBHID_REPORT_HEADER_TAG_GET(n) \
    (((n) >> USBHID_REPORT_HEADER_TAG_BIT) & USBHID_REPORT_HEADER_TAG_MASK)

#define USBHID_REPORT_HEADER_SIZE_SET(r,n)  ((r) \
    = ((r) & ~USBHID_REPORT_HEADER_SIZE) | USBHID_REPORT_HEADER_SIZE_n((n)))
#define USBHID_REPORT_HEADER_TYPE_SET(r,n)  ((r) \
    = ((r) & ~USBHID_REPORT_HEADER_TYPE) | USBHID_REPORT_HEADER_TYPE_n((n)))
#define USBHID_REPORT_HEADER_TAG_SET(r,n) \
    ((r) = ((r) & ~USBHID_REPORT_HEADER_TAG) | USBHID_REPORT_HEADER_TAG_n((n)))

// USBHID_REPORT_HEADER_SIZE_0B
#define USBHID_REPORT_HEADER_SIZE_0B 0

// USBHID_REPORT_HEADER_SIZE_1B
#define USBHID_REPORT_HEADER_SIZE_1B 1

// USBHID_REPORT_HEADER_SIZE_2B
#define USBHID_REPORT_HEADER_SIZE_2B 2

// USBHID_REPORT_HEADER_SIZE_4B
#define USBHID_REPORT_HEADER_SIZE_4B 3

