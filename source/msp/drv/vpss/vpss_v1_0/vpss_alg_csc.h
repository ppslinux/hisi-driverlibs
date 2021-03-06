#ifndef __VPSS_ALG_CSC_H__
#define __VPSS_ALG_CSC_H__

#include"hi_drv_mmz.h"
#include"hi_drv_video.h"


typedef enum 
{
    ALG_CS_eUnknown      = 0,
    ALG_CS_eYCbCr_709    = 1,
    ALG_CS_eYCbCr_601    = 2,
    ALG_CS_eRGB_709      = 3,
    ALG_CS_TYPE_BUTT

} ALG_CS_TYPE_E;


typedef enum 
{
    ALG_CS_RANGE_eUnknown = 0,
    ALG_CS_RANGE_FULL     = 1,
    ALG_CS_RANGE_LMTD     = 2,
    ALG_CS_RANGE_BUTT

} ALG_CS_RANGE_E;

typedef struct
{
    ALG_CS_TYPE_E eCsType;
    ALG_CS_RANGE_E eCsRange;
}ALG_CS_S;


typedef struct
{
    //ALG_CS_TYPE_E eInputCS;       //input color space type, should be set carefully according to the application situation.
    //ALG_CS_TYPE_E eOutputCS;      //output color space type, should be set carefully according to the application situation.
    //ALG_CS_RANGE_E eInputR;       //input color value range( full or limited), should be set carefully according to the application situation.
    //ALG_CS_RANGE_E eOutputR;      //output color value range( full or limited), should be set carefully according to the application situation.
    HI_DRV_COLOR_SPACE_E eInputCS;
    HI_DRV_COLOR_SPACE_E eOutputCS;
    HI_BOOL bIsBGRIn;
    HI_BOOL bIsBGROut;

    HI_U32 u32Bright;      //bright adjust value,range[0,100],default setting 50; 
    HI_U32 u32Contrst;     //contrast adjust value,range[0,100],default setting 50;
    HI_U32 u32Hue;         //hue adjust value,range[0,100],default setting 50;
    HI_U32 u32Satur;       //saturation adjust value,range[0,100],default setting 50;
    HI_U32 u32Kr;          //red component gain adjust value for color temperature adjust,range[0,100],default setting 50;
    HI_U32 u32Kg;          //green component gain adjust value for color temperature adjust,range[0,100],default setting 50;
    HI_U32 u32Kb;          //blue component gain adjust value for color temperature adjust,range[0,100],default setting 50;
} ALG_CSC_DRV_PARA_S;

typedef struct
{
    HI_S32 s32CscDcIn_0;    //input color space DC value of component 0;
    HI_S32 s32CscDcIn_1;    //input color space DC value of component 1;
    HI_S32 s32CscDcIn_2;    //input color space DC value of component 2;

    HI_S32 s32CscDcOut_0;   //output color space DC value of component 0;
    HI_S32 s32CscDcOut_1;   //output color space DC value of component 1;
    HI_S32 s32CscDcOut_2;   //output color space DC value of component 2;

    HI_S32 s32CscCoef_00;   //member 00 of 3*3 matrix
    HI_S32 s32CscCoef_01;   //member 01 of 3*3 matrix
    HI_S32 s32CscCoef_02;   //member 02 of 3*3 matrix

    HI_S32 s32CscCoef_10;   //member 10 of 3*3 matrix
    HI_S32 s32CscCoef_11;   //member 11 of 3*3 matrix
    HI_S32 s32CscCoef_12;   //member 12 of 3*3 matrix

    HI_S32 s32CscCoef_20;   //member 20 of 3*3 matrix
    HI_S32 s32CscCoef_21;   //member 21 of 3*3 matrix
    HI_S32 s32CscCoef_22;   //member 22 of 3*3 matrix
} ALG_CSC_RTL_PARA_S;



//HI_VOID GetCscType(HI_DRV_COLOR_SPACE_E eCSDrv, ALG_CS_S *pstCsAlg);
HI_VOID VPSS_ALG_CscCoefSet(ALG_CSC_DRV_PARA_S *pstCscDrvPara, ALG_CSC_RTL_PARA_S *pstCscRtlPara);

#endif /*__ALG_CSC_H__*/


