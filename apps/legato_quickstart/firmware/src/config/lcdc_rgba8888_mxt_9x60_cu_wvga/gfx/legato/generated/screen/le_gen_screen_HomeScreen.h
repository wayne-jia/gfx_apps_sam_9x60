#ifndef LE_GEN_SCREEN_HOMESCREEN_H
#define LE_GEN_SCREEN_HOMESCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* HomeScreen_panel_HomeScreen;
extern leWidget* HomeScreen_panel_pnlLeftMenu_1;
extern leWidget* HomeScreen_panel_pnlUp;
extern leWidget* HomeScreen_panel_pnlDown;
extern leLabelWidget* HomeScreen_label_Set_to;
extern leLabelWidget* HomeScreen_label_lblTargetTempValue;
extern leLabelWidget* HomeScreen_label_lblTargetDeg;
extern leWidget* HomeScreen_panel_pnlFan;
extern leImageWidget* HomeScreen_image_imgMchp;
extern leWidget* HomeScreen_panel_pnlTemp;
extern leWidget* HomeScreen_panel_pnlMode;
extern leWidget* HomeScreen_panel_pnlTempValues;
extern leButtonWidget* HomeScreen_ButtonHome;
extern leButtonWidget* HomeScreen_ButtonWiFi;
extern leButtonWidget* HomeScreen_ButtonSetting;
extern leButtonWidget* HomeScreen_ButtonFan;
extern leButtonWidget* HomeScreen_ButtonMode;
extern leButtonWidget* HomeScreen_ButtonUp;
extern leButtonWidget* HomeScreen_ButtonDown;
extern leImageWidget* HomeScreen_image_imgEllipse;
extern leImageWidget* HomeScreen_image_imgHomeSelect;
extern leImageWidget* HomeScreen_image_imgWifi_0;
extern leImageWidget* HomeScreen_image_imgSettings_0;
extern leImageWidget* HomeScreen_image_imgUp;
extern leImageWidget* HomeScreen_image_imgDown;
extern leImageWidget* HomeScreen_image_imgFan;
extern leLabelWidget* HomeScreen_label_lblAuto;
extern leLabelWidget* HomeScreen_label_lblFan;
extern leLabelWidget* HomeScreen_label_lblTime;
extern leLabelWidget* HomeScreen_label_lblCurrentTemp;
extern leImageWidget* HomeScreen_image_imgCool;
extern leLabelWidget* HomeScreen_label_lblCool;
extern leLabelWidget* HomeScreen_label_lblMode;
extern leLabelWidget* HomeScreen_label_lblTempValue;
extern leLabelWidget* HomeScreen_label_lblDegree;
extern leImageWidget* HomeScreen_image_imgKnob;
extern leWidget* HomeScreen_Panel_SetupScreen;
extern leLabelWidget* HomeScreen_label_lblSettings;
extern leLabelWidget* HomeScreen_LabelWidget_0;
extern leLabelWidget* HomeScreen_label_lblCommision;
extern leImageWidget* HomeScreen_ImageWidget_0;
extern leLabelWidget* HomeScreen_label_lblChangeNetType;
extern leWidget* HomeScreen_PanelWifiScreen;
extern leLabelWidget* HomeScreen_label_Wifi_configuration;
extern leLabelWidget* HomeScreen_label_Connected;
extern leImageWidget* HomeScreen_ImageWidget_1;
extern leImageWidget* HomeScreen_ImageWidget_2;
extern leLabelWidget* HomeScreen_label_lblOtherNetworks;
extern leImageWidget* HomeScreen_ImageWidget_3;
extern leImageWidget* HomeScreen_ImageWidget_4;
extern leImageWidget* HomeScreen_ImageWidget_5;
extern leLabelWidget* HomeScreen_label_lblCurrentWifi;
extern leLabelWidget* HomeScreen_label_lblScan;
extern leLabelWidget* HomeScreen_label_lblOtherNet1;
extern leLabelWidget* HomeScreen_label_lblOtherNet2;
extern leLabelWidget* HomeScreen_LabelWidget_1;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_HomeScreen_ButtonHome_OnReleased(leButtonWidget* btn);
void event_HomeScreen_ButtonWiFi_OnReleased(leButtonWidget* btn);
void event_HomeScreen_ButtonSetting_OnReleased(leButtonWidget* btn);
void event_HomeScreen_ButtonUp_OnReleased(leButtonWidget* btn);
void event_HomeScreen_ButtonDown_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_HomeScreen(void); // called when Legato is initialized
leResult screenShow_HomeScreen(void); // called when screen is shown
void screenHide_HomeScreen(void); // called when screen is hidden
void screenDestroy_HomeScreen(void); // called when Legato is destroyed
void screenUpdate_HomeScreen(void); // called when Legato is updating

leWidget* screenGetRoot_HomeScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void HomeScreen_OnShow(void); // called when this screen is shown

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_HOMESCREEN_H
