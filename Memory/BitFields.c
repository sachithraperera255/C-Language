#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

/*
    - In Embedded C, bit fields are a way to divide variables into smaller groups. Mostly used to
    read packet data.
*/

// The following struct represent bit-fields of a data packet.
struct Packets
{
    uint32_t crc:        2;
    uint32_t status:     1;
    uint32_t payload:   12;
    uint32_t bat:        3;
    uint32_t sensor:     3;
    uint32_t longAddr:   8;
    uint32_t shortAddr:  2;
    uint32_t addrMode:   1;
};

int main(void)
{
    // This variable is created to save the data packet.
    uint32_t readVal;

    // Reading the data packet
    printf("Enter the 32bits packet here: ");
    scanf("%X", &readVal);

    // cleating a instance of a structure.
    struct Packets packet;

    // Decoding and grouping the bit-fields in the data packet
    packet.crc = (uint8_t)(readVal & 0x3);
    packet.status = (uint8_t) ((readVal >> 2) & 0x1);
    packet.payload = (uint16_t) ((readVal >> 3) & 0xFFF);
    packet.bat = (uint8_t) ((readVal >> 15) & 0x7);
    packet.sensor = (uint8_t) ((readVal >> 18) & 0x7);
    packet.longAddr = (uint8_t) ((readVal >> 21) & 0xFF);
    packet.shortAddr = (uint8_t) ((readVal >> 29) & 0x3);
    packet.addrMode = (uint8_t) ((readVal >> 31) & 0x1);

    // Printing on the console
    printf("crc             :%x\n", packet.crc);
    printf("status          :%x\n", packet.status);
    printf("payload         :%x\n", packet.payload);
    printf("bat             :%x\n", packet.bat);
    printf("sensor          :%x\n", packet.sensor);
    printf("longAddr        :%x\n", packet.longAddr);
    printf("shortAddr       :%x\n", packet.shortAddr);
    printf("addrMode        :%x\n", packet.addrMode);

    printf("size of struct packet: %zu\n", sizeof(packet));


    return 0;
}