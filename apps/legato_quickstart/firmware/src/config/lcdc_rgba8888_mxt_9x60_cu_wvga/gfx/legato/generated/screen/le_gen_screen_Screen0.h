#ifndef LE_GEN_SCREEN_SCREEN0_H
#define LE_GEN_SCREEN_SCREEN0_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen0_BaseFillPanel;
extern leImageWidget* Screen0_BackSpeedoGaugeImage;
extern leImageWidget* Screen0_BackTachoGaugeImage;
extern leLabelWidget* Screen0_rpmLabel;
extern leImageWidget* Screen0_MicrochipLogo;
extern leWidget* Screen0_IndicatorsPanel;
extern leWidget* Screen0_SpeedoValuePanel;
extern leWidget* Screen0_RangePanel;
extern leWidget* Screen0_TurnModePanel;
extern leImageWidget* Screen0_MicrochipLogo_0;
extern leImageWidget* Screen0_MGSLogo;
extern leLabelWidget* Screen0_FreeRTOSLabel;
extern leImageWidget* Screen0_HeadlightIcon;
extern leImageWidget* Screen0_WarningIcon;
extern leImageWidget* Screen0_FuelIcon;
extern leLabelWidget* Screen0_mphLabel;
extern leLabelWidget* Screen0_SpeedoValueLabel;
extern leLabelWidget* Screen0_RangeUnitLabel;
extern leLabelWidget* Screen0_RangeValueLabel;
extern leImageWidget* Screen0_RangeValueBarBase;
extern leImageWidget* Screen0_ImageWidget_5;
extern leLabelWidget* Screen0_GearValueLabel;
extern leLabelWidget* Screen0_DriveModeLabel;
extern leImageWidget* Screen0_RangeValueBar;
extern leImageSequenceWidget* Screen0_RightTurnImageSeq;
extern leImageSequenceWidget* Screen0_LeftTurnImageSeq;
extern leImageWidget* Screen0_Directions;
extern leImageWidget* Screen0_DirectionArrows;
extern leLabelWidget* Screen0_DistanceLabel;
extern leLabelWidget* Screen0_DirectionLabel;
extern leWidget* Screen0_BaseFillPanel_0;
extern leWidget* Screen0_TouchPanelTacho;
extern leWidget* Screen0_TouchPanelSpeedo;
extern leButtonWidget* Screen0_StartButton;
extern leButtonWidget* Screen0_LeftTurnButton;
extern leButtonWidget* Screen0_RightTurnButton;
extern leButtonWidget* Screen0_MetricsButton;
extern leImageWidget* Screen0_ImageWidget_0_1_0;
extern leImageWidget* Screen0_ImageWidget_0_0;
extern leArcWidget* Screen0_TachoArc;
extern leArcWidget* Screen0_SpeedArc;
extern leLabelWidget* Screen0_MetricsLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen0_StartButton_OnPressed(leButtonWidget* btn);
void event_Screen0_StartButton_OnReleased(leButtonWidget* btn);
void event_Screen0_LeftTurnButton_OnPressed(leButtonWidget* btn);
void event_Screen0_LeftTurnButton_OnReleased(leButtonWidget* btn);
void event_Screen0_RightTurnButton_OnPressed(leButtonWidget* btn);
void event_Screen0_RightTurnButton_OnReleased(leButtonWidget* btn);
void event_Screen0_MetricsButton_OnPressed(leButtonWidget* btn);
void event_Screen0_MetricsButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen0(void); // called when Legato is initialized
leResult screenShow_Screen0(void); // called when screen is shown
void screenHide_Screen0(void); // called when screen is hidden
void screenDestroy_Screen0(void); // called when Legato is destroyed
void screenUpdate_Screen0(void); // called when Legato is updating

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen0_OnShow(void); // called when this screen is shown
void Screen0_OnHide(void); // called when this screen is hidden
void Screen0_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN0_H
