#ifndef RADIO_H
#define RADIO_H

#include "hal_types.h"
#include "debug.h"

#define RADIO_MAX_PACKET_LENGTH     72u
#define barkerLengthInByte 7
#define barkerLengthInBit barkerLengthInByte*8


typedef struct
{
    U8   *Radio_ConfigurationArray;

    U8   Radio_ChannelNumber;
    U8   Radio_PacketLength;
    U8   Radio_State_After_Power_Up;

    U16  Radio_Delay_Cnt_After_Reset;
} tRadioConfiguration;

void vRadio_PowerUp(void);
void vRadio_Init(void);
void vRadio_config_1st(void);
void vRadio_config_2nd(void);
void vRadio_config_ack(void);
uint8   gRadio_CheckReceived(void);
uint8 gRadio_CheckReceived_VariablePacket(void);
uint8   gRadio_CheckTransmitted(void);
void  vRadio_StartRX(U8);
void vRadio_StartRX_1st(U8 channel);
void vRadio_StartRX_2nd(U8 channel);
void vRadio_StartRX_ack(U8 channel);
uint8  vRadio_StartTx(U8, U8 *,U8 len);

void RXHandlerInGDO0_SI4463(void);

uint8 gSampleCode_StringCompare(U8* pbiPacketContent, U8* pbiString, U8 lenght);

uint8 vSampleCode_SendFixPacket(U8 * Packet,U8 len);
void SI4463_Transmit(U8 * Packet,U8 length);
uint8 New_SI4463_Transmit(U8 * pSrc,U8 len);

uint8 Radio_Receive_FixedLength(void);

uint8 SI4463_Config_Transmit_dualrate(U8 * pSrc1,U8 len1,U8 * pSrc2,U8 len2);
uint8 compare(uint32 *input);
void paixu(unsigned int input[],unsigned char output[],unsigned char num);
#endif
