/*
 * _DIO.h
 *
 * Created: 8/28/2022 3:11:47 PM
 *  Author: Barhoom Ali
 */ 

// ┏┓ ┏┓                      ┏┓                              ┏┓  ┏┓             ┏┓
//┏┛┗┓┃┃                      ┃┃                             ┏┛┗┓┏┛┗┓            ┃┃
//┗┓┏┛┃┗━┓┏┓┏━━┓    ┏━━┓┏━━┓┏━┛┃┏━━┓    ┏┓┏━━┓    ┏┓┏┓┏┓┏━┓┏┓┗┓┏┛┗┓┏┛┏━━┓┏━┓     ┃┗━┓┏┓ ┏┓
// ┃┃ ┃┏┓┃┣┫┃━━┫    ┃┏━┛┃┏┓┃┃┏┓┃┃┏┓┃    ┣┫┃━━┫    ┃┗┛┗┛┃┃┏┛┣┫ ┃┃  ┃┃ ┃┏┓┃┃┏┓┓    ┃┏┓┃┃┃ ┃┃
// ┃┗┓┃┃┃┃┃┃┣━━┃    ┃┗━┓┃┗┛┃┃┗┛┃┃┃━┫    ┃┃┣━━┃    ┗┓┏┓┏┛┃┃ ┃┃ ┃┗┓ ┃┗┓┃┃━┫┃┃┃┃    ┃┗┛┃┃┗━┛┃
// ┗━┛┗┛┗┛┗┛┗━━┛    ┗━━┛┗━━┛┗━━┛┗━━┛    ┗┛┗━━┛     ┗┛┗┛ ┗┛ ┗┛ ┗━┛ ┗━┛┗━━┛┗┛┗┛    ┗━━┛┗━┓┏┛
//                                                                                   ┏━┛┃
//                                                                                   ┗━━┛
// Ibrahim Mohamed Hamdy Hassan

#ifndef _DIO_H_
#define _DIO_H_

#include "../../Utilities/_REG.h"
#include "../../Utilities/_BIT_MATH.h"
#include "../../Utilities/_STD_TYPES_DEFS.h"

typedef enum EN_DIO_ERROR {
    DIO_OK = 0,
    INVALID_PORT,
    INVALID_PIN,
    INVALID_DIR,
    INVALID_VALUE
} EN_DIO_ERROR;

// DIO.c

EN_DIO_ERROR DIO_init(uint8_t port, uint8_t pin, uint8_t direction);

EN_DIO_ERROR DIO_write(uint8_t port, uint8_t pin, uint8_t value);

EN_DIO_ERROR DIO_toggle(uint8_t port, uint8_t pin);

EN_DIO_ERROR DIO_read(uint8_t port, uint8_t pin, uint8_t * valueRead);

// DIO_test.c

void DIO_init_test();

void DIO_write_test();

void DIO_read_test();

void DIO_toggle_test();

#endif /* _DIO_H_ */