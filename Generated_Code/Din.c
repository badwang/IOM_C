/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Din.c
**     Project     : IOM_C
**     Processor   : MC9S08PA4VTJ
**     Component   : BitsIO
**     Version     : Component 02.108, Driver 03.28, CPU db: 3.00.000
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2015-02-09, 15:28, # CodeGen: 15
**     Abstract    :
**         This component "BitsIO" implements a multi-bit input/output.
**         It uses selected pins of one 1-bit to 8-bit port.
**         Note: This component is set to work in Input direction only.
**     Settings    :
**         Port name                   : PTA
**
**         Bit mask of the port        : $000F
**         Number of bits/pins         : 4
**         Single bit numbers          : 0 to 3
**         Values range                : 0 to 15
**
**         Initial direction           : Input (direction cannot be changed)
**         Initial output value        : 0 = 000H
**         Initial pull option         : off
**
**         Port data register          : PORT_PTAD [$0000]
**         Port control register       : PORT_PTAOE [$30B0]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    20   |   PTA0_KBI0P0_FTM0CH0_ACMP0_ADP0
**                    1      |    19   |   PTA1_KBI0P1_FTM0CH1_ACMP1_ADP1
**                    2      |    18   |   PTA2_KBI0P2_FTM0CH0_RXD0_ADP2
**                    3      |    17   |   PTA3_KBI0P3_FTM0CH1_TXD0_ADP3
**             ----------------------------------------------------
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - byte Din_GetVal(void);
**         GetBit - bool Din_GetBit(byte Bit);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Din.c
** @version 03.28
** @brief
**         This component "BitsIO" implements a multi-bit input/output.
**         It uses selected pins of one 1-bit to 8-bit port.
**         Note: This component is set to work in Input direction only.
*/         
/*!
**  @addtogroup Din_module Din module documentation
**  @{
*/         

/* MODULE Din. */

#include "Din.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  Din_GetMsk (component BitsIO)
**
**     Description :
**         The method returns a bit mask which corresponds to the 
**         required bit position.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static const  byte Din_Table[4U] = {   /* Table of mask constants */
   0x01U, 0x02U, 0x04U, 0x08U
};

static byte Din_GetMsk (byte PinIndex)
{
  return (byte)((PinIndex<4U) ? Din_Table[PinIndex] : 0U); /* Check range and return appropriate bit mask */
}

/*
** ===================================================================
**     Method      :  Din_GetVal (component BitsIO)
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pins and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Input direction only.
**     Parameters  : None
**     Returns     :
**         ---        - Input value (0 to 15)
** ===================================================================
*/
byte Din_GetVal(void)
{
  return (byte)(getReg8(PORT_PTAD) & 0x0FU); /* Return port data */
}

/*
** ===================================================================
**     Method      :  Din_GetBit (component BitsIO)
**     Description :
**         This method returns the specified bit of the input value.
**           a) direction = Input  : reads the input value from pins
**                                   and returns the specified bit
**           b) direction = Output : returns the specified bit
**                                   of the last written value
**         Note: This component is set to work in Input direction only.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to read (0 to 3)
**     Returns     :
**         ---        - Value of the specified bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
** ===================================================================
*/
bool Din_GetBit(byte Bit)
{
  byte const Mask = Din_GetMsk(Bit);   /* Temporary variable - bit mask to test */
  return (bool)(((getReg8(PORT_PTAD) & Mask) == Mask)? 1U: 0U); /* Test if specified bit of port register is set */
}


/* END Din. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
