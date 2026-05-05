#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

/*
    - In Embedded C, bit fields are a way to divide variables into smaller groups. Mostly used to
    read packet data.
*/

// The following struct represent bit-fields of a data packet.
union Packets
{
    // This variable is created to save the data packet.
    uint32_t readVal;

    struct
    {
        uint32_t crc:        2;
        uint32_t status:     1;
        uint32_t payload:   12;
        uint32_t bat:        3;
        uint32_t sensor:     3;
        uint32_t longAddr:   8;
        uint32_t shortAddr:  2;
        uint32_t addrMode:   1;
    }BitFields;   
};

// The above union let store 32-bits value and letting the struct interpret the same bits and name field
// without copying the memory.

int main(void)
{
    union Packets val;
    // Reading the data packet
    printf("Enter the 32bits packet here: ");
    scanf("%x", &val.readVal);

    // // cleating a instance of a structure.
    // struct Packets packet;

    // // Decoding and grouping the bit-fields in the data packet
    // packet.crc = (uint8_t)(readVal & 0x3);
    // packet.status = (uint8_t) ((readVal >> 2) & 0x1);
    // packet.payload = (uint16_t) ((readVal >> 3) & 0xFFF);
    // packet.bat = (uint8_t) ((readVal >> 15) & 0x7);
    // packet.sensor = (uint8_t) ((readVal >> 18) & 0x7);
    // packet.longAddr = (uint8_t) ((readVal >> 21) & 0xFF);
    // packet.shortAddr = (uint8_t) ((readVal >> 29) & 0x3);
    // packet.addrMode = (uint8_t) ((readVal >> 31) & 0x1);

    // Printing on the console
    printf("crc             :%x\n", val.BitFields.crc);
    printf("status          :%x\n", val.BitFields.status);
    printf("payload         :%x\n", val.BitFields.payload);
    printf("bat             :%x\n", val.BitFields.bat);
    printf("sensor          :%x\n", val.BitFields.sensor);
    printf("longAddr        :%x\n", val.BitFields.longAddr);
    printf("shortAddr       :%x\n", val.BitFields.shortAddr);
    printf("addrMode        :%x\n", val.BitFields.addrMode);

    printf("size of the union: %zu\n", sizeof(val));
    printf("size of the struct: %zu\n", sizeof(val.BitFields));


    return 0;
}