#include "gfx/legato/generated/screen/le_gen_screen_HomeScreen.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;

leWidget* HomeScreen_panel_HomeScreen;
leWidget* HomeScreen_panel_pnlLeftMenu_1;
leWidget* HomeScreen_panel_pnlUp;
leWidget* HomeScreen_panel_pnlDown;
leLabelWidget* HomeScreen_label_Set_to;
leLabelWidget* HomeScreen_label_lblTargetTempValue;
leLabelWidget* HomeScreen_label_lblTargetDeg;
leWidget* HomeScreen_panel_pnlFan;
leImageWidget* HomeScreen_image_imgMchp;
leWidget* HomeScreen_panel_pnlTemp;
leWidget* HomeScreen_panel_pnlMode;
leWidget* HomeScreen_panel_pnlTempValues;
leButtonWidget* HomeScreen_ButtonHome;
leButtonWidget* HomeScreen_ButtonWiFi;
leButtonWidget* HomeScreen_ButtonSetting;
leButtonWidget* HomeScreen_ButtonFan;
leButtonWidget* HomeScreen_ButtonMode;
leButtonWidget* HomeScreen_ButtonUp;
leButtonWidget* HomeScreen_ButtonDown;
leImageWidget* HomeScreen_image_imgEllipse;
leImageWidget* HomeScreen_image_imgHomeSelect;
leImageWidget* HomeScreen_image_imgWifi_0;
leImageWidget* HomeScreen_image_imgSettings_0;
leImageWidget* HomeScreen_image_imgUp;
leImageWidget* HomeScreen_image_imgDown;
leImageWidget* HomeScreen_image_imgFan;
leLabelWidget* HomeScreen_label_lblAuto;
leLabelWidget* HomeScreen_label_lblFan;
leLabelWidget* HomeScreen_label_lblTime;
leLabelWidget* HomeScreen_label_lblCurrentTemp;
leImageWidget* HomeScreen_image_imgCool;
leLabelWidget* HomeScreen_label_lblCool;
leLabelWidget* HomeScreen_label_lblMode;
leLabelWidget* HomeScreen_label_lblTempValue;
leLabelWidget* HomeScreen_label_lblDegree;
leImageWidget* HomeScreen_image_imgKnob;
leWidget* HomeScreen_Panel_SetupScreen;
leLabelWidget* HomeScreen_label_lblSettings;
leLabelWidget* HomeScreen_LabelWidget_0;
leLabelWidget* HomeScreen_label_lblCommision;
leImageWidget* HomeScreen_ImageWidget_0;
leLabelWidget* HomeScreen_label_lblChangeNetType;
leWidget* HomeScreen_PanelWifiScreen;
leLabelWidget* HomeScreen_label_Wifi_configuration;
leLabelWidget* HomeScreen_label_Connected;
leImageWidget* HomeScreen_ImageWidget_1;
leImageWidget* HomeScreen_ImageWidget_2;
leLabelWidget* HomeScreen_label_lblOtherNetworks;
leImageWidget* HomeScreen_ImageWidget_3;
leImageWidget* HomeScreen_ImageWidget_4;
leImageWidget* HomeScreen_ImageWidget_5;
leLabelWidget* HomeScreen_label_lblCurrentWifi;
leLabelWidget* HomeScreen_label_lblScan;
leLabelWidget* HomeScreen_label_lblOtherNet1;
leLabelWidget* HomeScreen_label_lblOtherNet2;
leLabelWidget* HomeScreen_LabelWidget_1;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_HomeScreen(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_HomeScreen(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, LE_DEFAULT_SCREEN_WIDTH, LE_DEFAULT_SCREEN_HEIGHT);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    HomeScreen_panel_HomeScreen = leWidget_New();
    HomeScreen_panel_HomeScreen->fn->setPosition(HomeScreen_panel_HomeScreen, 0, 0);
    HomeScreen_panel_HomeScreen->fn->setSize(HomeScreen_panel_HomeScreen, 800, 480);
    HomeScreen_panel_HomeScreen->fn->setScheme(HomeScreen_panel_HomeScreen, &panel_whitesmoke);
    root0->fn->addChild(root0, (leWidget*)HomeScreen_panel_HomeScreen);

    HomeScreen_panel_pnlLeftMenu_1 = leWidget_New();
    HomeScreen_panel_pnlLeftMenu_1->fn->setPosition(HomeScreen_panel_pnlLeftMenu_1, 0, 24);
    HomeScreen_panel_pnlLeftMenu_1->fn->setSize(HomeScreen_panel_pnlLeftMenu_1, 160, 432);
    HomeScreen_panel_pnlLeftMenu_1->fn->setBackgroundType(HomeScreen_panel_pnlLeftMenu_1, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_panel_pnlLeftMenu_1);

    HomeScreen_image_imgHomeSelect = leImageWidget_New();
    HomeScreen_image_imgHomeSelect->fn->setPosition(HomeScreen_image_imgHomeSelect, 0, 0);
    HomeScreen_image_imgHomeSelect->fn->setSize(HomeScreen_image_imgHomeSelect, 160, 134);
    HomeScreen_image_imgHomeSelect->fn->setBackgroundType(HomeScreen_image_imgHomeSelect, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgHomeSelect->fn->setBorderType(HomeScreen_image_imgHomeSelect, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgHomeSelect->fn->setImage(HomeScreen_image_imgHomeSelect, (leImage*)&figmaImg_imgHomeSelect);
    HomeScreen_panel_pnlLeftMenu_1->fn->addChild(HomeScreen_panel_pnlLeftMenu_1, (leWidget*)HomeScreen_image_imgHomeSelect);

    HomeScreen_image_imgWifi_0 = leImageWidget_New();
    HomeScreen_image_imgWifi_0->fn->setPosition(HomeScreen_image_imgWifi_0, 0, 150);
    HomeScreen_image_imgWifi_0->fn->setSize(HomeScreen_image_imgWifi_0, 160, 134);
    HomeScreen_image_imgWifi_0->fn->setBackgroundType(HomeScreen_image_imgWifi_0, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgWifi_0->fn->setBorderType(HomeScreen_image_imgWifi_0, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgWifi_0->fn->setImage(HomeScreen_image_imgWifi_0, (leImage*)&figmaImg_imgWifi);
    HomeScreen_panel_pnlLeftMenu_1->fn->addChild(HomeScreen_panel_pnlLeftMenu_1, (leWidget*)HomeScreen_image_imgWifi_0);

    HomeScreen_image_imgSettings_0 = leImageWidget_New();
    HomeScreen_image_imgSettings_0->fn->setPosition(HomeScreen_image_imgSettings_0, 0, 299);
    HomeScreen_image_imgSettings_0->fn->setSize(HomeScreen_image_imgSettings_0, 160, 134);
    HomeScreen_image_imgSettings_0->fn->setBackgroundType(HomeScreen_image_imgSettings_0, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgSettings_0->fn->setBorderType(HomeScreen_image_imgSettings_0, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgSettings_0->fn->setImage(HomeScreen_image_imgSettings_0, (leImage*)&figmaImg_imgSettings);
    HomeScreen_panel_pnlLeftMenu_1->fn->addChild(HomeScreen_panel_pnlLeftMenu_1, (leWidget*)HomeScreen_image_imgSettings_0);

    HomeScreen_panel_pnlUp = leWidget_New();
    HomeScreen_panel_pnlUp->fn->setPosition(HomeScreen_panel_pnlUp, 668, 23);
    HomeScreen_panel_pnlUp->fn->setSize(HomeScreen_panel_pnlUp, 112, 113);
    HomeScreen_panel_pnlUp->fn->setScheme(HomeScreen_panel_pnlUp, &panel_white);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_panel_pnlUp);

    HomeScreen_image_imgUp = leImageWidget_New();
    HomeScreen_image_imgUp->fn->setPosition(HomeScreen_image_imgUp, 29, 35);
    HomeScreen_image_imgUp->fn->setSize(HomeScreen_image_imgUp, 57, 35);
    HomeScreen_image_imgUp->fn->setBackgroundType(HomeScreen_image_imgUp, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgUp->fn->setBorderType(HomeScreen_image_imgUp, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgUp->fn->setImage(HomeScreen_image_imgUp, (leImage*)&figmaImg_imgUp);
    HomeScreen_panel_pnlUp->fn->addChild(HomeScreen_panel_pnlUp, (leWidget*)HomeScreen_image_imgUp);

    HomeScreen_panel_pnlDown = leWidget_New();
    HomeScreen_panel_pnlDown->fn->setPosition(HomeScreen_panel_pnlDown, 668, 344);
    HomeScreen_panel_pnlDown->fn->setSize(HomeScreen_panel_pnlDown, 112, 113);
    HomeScreen_panel_pnlDown->fn->setScheme(HomeScreen_panel_pnlDown, &panel_white);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_panel_pnlDown);

    HomeScreen_image_imgDown = leImageWidget_New();
    HomeScreen_image_imgDown->fn->setPosition(HomeScreen_image_imgDown, 27, 44);
    HomeScreen_image_imgDown->fn->setSize(HomeScreen_image_imgDown, 57, 35);
    HomeScreen_image_imgDown->fn->setBackgroundType(HomeScreen_image_imgDown, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgDown->fn->setBorderType(HomeScreen_image_imgDown, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgDown->fn->setImage(HomeScreen_image_imgDown, (leImage*)&figmaImg_imgDown);
    HomeScreen_panel_pnlDown->fn->addChild(HomeScreen_panel_pnlDown, (leWidget*)HomeScreen_image_imgDown);

    HomeScreen_label_Set_to = leLabelWidget_New();
    HomeScreen_label_Set_to->fn->setPosition(HomeScreen_label_Set_to, 698, 189);
    HomeScreen_label_Set_to->fn->setSize(HomeScreen_label_Set_to, 46, 19);
    HomeScreen_label_Set_to->fn->setScheme(HomeScreen_label_Set_to, &text_silver);
    HomeScreen_label_Set_to->fn->setBackgroundType(HomeScreen_label_Set_to, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_Set_to->fn->setVAlignment(HomeScreen_label_Set_to, LE_VALIGN_TOP);
    HomeScreen_label_Set_to->fn->setMargins(HomeScreen_label_Set_to, 0, 0, 0, 0);
    HomeScreen_label_Set_to->fn->setString(HomeScreen_label_Set_to, (leString*)&string_figmaStr_Set_to);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_label_Set_to);

    HomeScreen_label_lblTargetTempValue = leLabelWidget_New();
    HomeScreen_label_lblTargetTempValue->fn->setPosition(HomeScreen_label_lblTargetTempValue, 665, 232);
    HomeScreen_label_lblTargetTempValue->fn->setSize(HomeScreen_label_lblTargetTempValue, 92, 76);
    HomeScreen_label_lblTargetTempValue->fn->setScheme(HomeScreen_label_lblTargetTempValue, &text_silver);
    HomeScreen_label_lblTargetTempValue->fn->setBackgroundType(HomeScreen_label_lblTargetTempValue, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblTargetTempValue->fn->setVAlignment(HomeScreen_label_lblTargetTempValue, LE_VALIGN_TOP);
    HomeScreen_label_lblTargetTempValue->fn->setMargins(HomeScreen_label_lblTargetTempValue, 0, 0, 0, 0);
    HomeScreen_label_lblTargetTempValue->fn->setString(HomeScreen_label_lblTargetTempValue, (leString*)&string_figmaStr_lblTargetTempValue);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_label_lblTargetTempValue);

    HomeScreen_label_lblTargetDeg = leLabelWidget_New();
    HomeScreen_label_lblTargetDeg->fn->setPosition(HomeScreen_label_lblTargetDeg, 755, 232);
    HomeScreen_label_lblTargetDeg->fn->setSize(HomeScreen_label_lblTargetDeg, 15, 23);
    HomeScreen_label_lblTargetDeg->fn->setScheme(HomeScreen_label_lblTargetDeg, &text_silver);
    HomeScreen_label_lblTargetDeg->fn->setBackgroundType(HomeScreen_label_lblTargetDeg, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblTargetDeg->fn->setVAlignment(HomeScreen_label_lblTargetDeg, LE_VALIGN_TOP);
    HomeScreen_label_lblTargetDeg->fn->setMargins(HomeScreen_label_lblTargetDeg, 0, 0, 0, 0);
    HomeScreen_label_lblTargetDeg->fn->setString(HomeScreen_label_lblTargetDeg, (leString*)&string_figmaStr_lblTargetDeg);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_label_lblTargetDeg);

    HomeScreen_panel_pnlFan = leWidget_New();
    HomeScreen_panel_pnlFan->fn->setPosition(HomeScreen_panel_pnlFan, 230, 379);
    HomeScreen_panel_pnlFan->fn->setSize(HomeScreen_panel_pnlFan, 178, 76);
    HomeScreen_panel_pnlFan->fn->setScheme(HomeScreen_panel_pnlFan, &panel_white);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_panel_pnlFan);

    HomeScreen_image_imgFan = leImageWidget_New();
    HomeScreen_image_imgFan->fn->setPosition(HomeScreen_image_imgFan, 130, 19);
    HomeScreen_image_imgFan->fn->setSize(HomeScreen_image_imgFan, 37, 37);
    HomeScreen_image_imgFan->fn->setBackgroundType(HomeScreen_image_imgFan, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgFan->fn->setBorderType(HomeScreen_image_imgFan, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgFan->fn->setImage(HomeScreen_image_imgFan, (leImage*)&figmaImg_imgFan);
    HomeScreen_panel_pnlFan->fn->addChild(HomeScreen_panel_pnlFan, (leWidget*)HomeScreen_image_imgFan);

    HomeScreen_label_lblAuto = leLabelWidget_New();
    HomeScreen_label_lblAuto->fn->setPosition(HomeScreen_label_lblAuto, 20, 42);
    HomeScreen_label_lblAuto->fn->setSize(HomeScreen_label_lblAuto, 60, 28);
    HomeScreen_label_lblAuto->fn->setScheme(HomeScreen_label_lblAuto, &text_darkcyan);
    HomeScreen_label_lblAuto->fn->setBackgroundType(HomeScreen_label_lblAuto, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblAuto->fn->setVAlignment(HomeScreen_label_lblAuto, LE_VALIGN_TOP);
    HomeScreen_label_lblAuto->fn->setMargins(HomeScreen_label_lblAuto, 0, 0, 0, 0);
    HomeScreen_label_lblAuto->fn->setString(HomeScreen_label_lblAuto, (leString*)&string_figmaStr_lblAuto);
    HomeScreen_panel_pnlFan->fn->addChild(HomeScreen_panel_pnlFan, (leWidget*)HomeScreen_label_lblAuto);

    HomeScreen_label_lblFan = leLabelWidget_New();
    HomeScreen_label_lblFan->fn->setPosition(HomeScreen_label_lblFan, 20, 15);
    HomeScreen_label_lblFan->fn->setSize(HomeScreen_label_lblFan, 33, 21);
    HomeScreen_label_lblFan->fn->setScheme(HomeScreen_label_lblFan, &text_silver);
    HomeScreen_label_lblFan->fn->setBackgroundType(HomeScreen_label_lblFan, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblFan->fn->setHAlignment(HomeScreen_label_lblFan, LE_HALIGN_CENTER);
    HomeScreen_label_lblFan->fn->setVAlignment(HomeScreen_label_lblFan, LE_VALIGN_TOP);
    HomeScreen_label_lblFan->fn->setMargins(HomeScreen_label_lblFan, 0, 0, 0, 0);
    HomeScreen_label_lblFan->fn->setString(HomeScreen_label_lblFan, (leString*)&string_figmaStr_lblFan);
    HomeScreen_panel_pnlFan->fn->addChild(HomeScreen_panel_pnlFan, (leWidget*)HomeScreen_label_lblFan);

    HomeScreen_image_imgMchp = leImageWidget_New();
    HomeScreen_image_imgMchp->fn->setPosition(HomeScreen_image_imgMchp, 357, 23);
    HomeScreen_image_imgMchp->fn->setSize(HomeScreen_image_imgMchp, 117, 18);
    HomeScreen_image_imgMchp->fn->setBackgroundType(HomeScreen_image_imgMchp, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgMchp->fn->setBorderType(HomeScreen_image_imgMchp, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgMchp->fn->setImage(HomeScreen_image_imgMchp, (leImage*)&figmaImg_imgMchp);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_image_imgMchp);

    HomeScreen_panel_pnlTemp = leWidget_New();
    HomeScreen_panel_pnlTemp->fn->setPosition(HomeScreen_panel_pnlTemp, 303, 146);
    HomeScreen_panel_pnlTemp->fn->setSize(HomeScreen_panel_pnlTemp, 238, 196);
    HomeScreen_panel_pnlTemp->fn->setBackgroundType(HomeScreen_panel_pnlTemp, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_panel_pnlTemp);

    HomeScreen_label_lblTime = leLabelWidget_New();
    HomeScreen_label_lblTime->fn->setPosition(HomeScreen_label_lblTime, 98, 176);
    HomeScreen_label_lblTime->fn->setSize(HomeScreen_label_lblTime, 62, 23);
    HomeScreen_label_lblTime->fn->setScheme(HomeScreen_label_lblTime, &text_darkcyan);
    HomeScreen_label_lblTime->fn->setBackgroundType(HomeScreen_label_lblTime, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblTime->fn->setVAlignment(HomeScreen_label_lblTime, LE_VALIGN_TOP);
    HomeScreen_label_lblTime->fn->setMargins(HomeScreen_label_lblTime, 0, 0, 0, 0);
    HomeScreen_label_lblTime->fn->setString(HomeScreen_label_lblTime, (leString*)&string_figmaStr_lblTime);
    HomeScreen_panel_pnlTemp->fn->addChild(HomeScreen_panel_pnlTemp, (leWidget*)HomeScreen_label_lblTime);

    HomeScreen_label_lblCurrentTemp = leLabelWidget_New();
    HomeScreen_label_lblCurrentTemp->fn->setPosition(HomeScreen_label_lblCurrentTemp, 73, 0);
    HomeScreen_label_lblCurrentTemp->fn->setSize(HomeScreen_label_lblCurrentTemp, 112, 24);
    HomeScreen_label_lblCurrentTemp->fn->setScheme(HomeScreen_label_lblCurrentTemp, &text_darkcyan);
    HomeScreen_label_lblCurrentTemp->fn->setBackgroundType(HomeScreen_label_lblCurrentTemp, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblCurrentTemp->fn->setVAlignment(HomeScreen_label_lblCurrentTemp, LE_VALIGN_TOP);
    HomeScreen_label_lblCurrentTemp->fn->setMargins(HomeScreen_label_lblCurrentTemp, 0, 0, 0, 0);
    HomeScreen_label_lblCurrentTemp->fn->setString(HomeScreen_label_lblCurrentTemp, (leString*)&string_figmaStr_lblCurrentTemp);
    HomeScreen_panel_pnlTemp->fn->addChild(HomeScreen_panel_pnlTemp, (leWidget*)HomeScreen_label_lblCurrentTemp);

    HomeScreen_panel_pnlMode = leWidget_New();
    HomeScreen_panel_pnlMode->fn->setPosition(HomeScreen_panel_pnlMode, 424, 379);
    HomeScreen_panel_pnlMode->fn->setSize(HomeScreen_panel_pnlMode, 178, 76);
    HomeScreen_panel_pnlMode->fn->setScheme(HomeScreen_panel_pnlMode, &panel_white);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_panel_pnlMode);

    HomeScreen_image_imgCool = leImageWidget_New();
    HomeScreen_image_imgCool->fn->setPosition(HomeScreen_image_imgCool, 133, 21);
    HomeScreen_image_imgCool->fn->setSize(HomeScreen_image_imgCool, 34, 34);
    HomeScreen_image_imgCool->fn->setBackgroundType(HomeScreen_image_imgCool, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgCool->fn->setBorderType(HomeScreen_image_imgCool, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgCool->fn->setImage(HomeScreen_image_imgCool, (leImage*)&figmaImg_imgCool);
    HomeScreen_panel_pnlMode->fn->addChild(HomeScreen_panel_pnlMode, (leWidget*)HomeScreen_image_imgCool);

    HomeScreen_label_lblCool = leLabelWidget_New();
    HomeScreen_label_lblCool->fn->setPosition(HomeScreen_label_lblCool, 20, 42);
    HomeScreen_label_lblCool->fn->setSize(HomeScreen_label_lblCool, 55, 26);
    HomeScreen_label_lblCool->fn->setScheme(HomeScreen_label_lblCool, &text_darkcyan);
    HomeScreen_label_lblCool->fn->setBackgroundType(HomeScreen_label_lblCool, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblCool->fn->setVAlignment(HomeScreen_label_lblCool, LE_VALIGN_TOP);
    HomeScreen_label_lblCool->fn->setMargins(HomeScreen_label_lblCool, 0, 0, 0, 0);
    HomeScreen_label_lblCool->fn->setString(HomeScreen_label_lblCool, (leString*)&string_figmaStr_lblCool);
    HomeScreen_panel_pnlMode->fn->addChild(HomeScreen_panel_pnlMode, (leWidget*)HomeScreen_label_lblCool);

    HomeScreen_label_lblMode = leLabelWidget_New();
    HomeScreen_label_lblMode->fn->setPosition(HomeScreen_label_lblMode, 18, 15);
    HomeScreen_label_lblMode->fn->setSize(HomeScreen_label_lblMode, 52, 22);
    HomeScreen_label_lblMode->fn->setScheme(HomeScreen_label_lblMode, &text_silver);
    HomeScreen_label_lblMode->fn->setBackgroundType(HomeScreen_label_lblMode, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblMode->fn->setHAlignment(HomeScreen_label_lblMode, LE_HALIGN_CENTER);
    HomeScreen_label_lblMode->fn->setVAlignment(HomeScreen_label_lblMode, LE_VALIGN_TOP);
    HomeScreen_label_lblMode->fn->setMargins(HomeScreen_label_lblMode, 0, 0, 0, 0);
    HomeScreen_label_lblMode->fn->setString(HomeScreen_label_lblMode, (leString*)&string_figmaStr_lblMode);
    HomeScreen_panel_pnlMode->fn->addChild(HomeScreen_panel_pnlMode, (leWidget*)HomeScreen_label_lblMode);

    HomeScreen_panel_pnlTempValues = leWidget_New();
    HomeScreen_panel_pnlTempValues->fn->setPosition(HomeScreen_panel_pnlTempValues, 303, 173);
    HomeScreen_panel_pnlTempValues->fn->setSize(HomeScreen_panel_pnlTempValues, 257, 134);
    HomeScreen_panel_pnlTempValues->fn->setBackgroundType(HomeScreen_panel_pnlTempValues, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_panel_pnlTempValues);

    HomeScreen_label_lblTempValue = leLabelWidget_New();
    HomeScreen_label_lblTempValue->fn->setPosition(HomeScreen_label_lblTempValue, 30, -9);
    HomeScreen_label_lblTempValue->fn->setSize(HomeScreen_label_lblTempValue, 190, 133);
    HomeScreen_label_lblTempValue->fn->setScheme(HomeScreen_label_lblTempValue, &text_darkcyan);
    HomeScreen_label_lblTempValue->fn->setBackgroundType(HomeScreen_label_lblTempValue, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblTempValue->fn->setHAlignment(HomeScreen_label_lblTempValue, LE_HALIGN_CENTER);
    HomeScreen_label_lblTempValue->fn->setMargins(HomeScreen_label_lblTempValue, 0, 0, 0, 0);
    HomeScreen_label_lblTempValue->fn->setString(HomeScreen_label_lblTempValue, (leString*)&string_figmaStr_lblTempValue);
    HomeScreen_panel_pnlTempValues->fn->addChild(HomeScreen_panel_pnlTempValues, (leWidget*)HomeScreen_label_lblTempValue);

    HomeScreen_label_lblDegree = leLabelWidget_New();
    HomeScreen_label_lblDegree->fn->setPosition(HomeScreen_label_lblDegree, 207, 0);
    HomeScreen_label_lblDegree->fn->setSize(HomeScreen_label_lblDegree, 50, 43);
    HomeScreen_label_lblDegree->fn->setScheme(HomeScreen_label_lblDegree, &text_darkcyan);
    HomeScreen_label_lblDegree->fn->setBackgroundType(HomeScreen_label_lblDegree, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblDegree->fn->setVAlignment(HomeScreen_label_lblDegree, LE_VALIGN_TOP);
    HomeScreen_label_lblDegree->fn->setMargins(HomeScreen_label_lblDegree, 0, 0, 0, 0);
    HomeScreen_label_lblDegree->fn->setString(HomeScreen_label_lblDegree, (leString*)&string_figmaStr_lblDegree);
    HomeScreen_panel_pnlTempValues->fn->addChild(HomeScreen_panel_pnlTempValues, (leWidget*)HomeScreen_label_lblDegree);

    HomeScreen_ButtonHome = leButtonWidget_New();
    HomeScreen_ButtonHome->fn->setPosition(HomeScreen_ButtonHome, 0, 23);
    HomeScreen_ButtonHome->fn->setSize(HomeScreen_ButtonHome, 161, 138);
    HomeScreen_ButtonHome->fn->setScheme(HomeScreen_ButtonHome, &WhiteScheme);
    HomeScreen_ButtonHome->fn->setBackgroundType(HomeScreen_ButtonHome, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ButtonHome->fn->setBorderType(HomeScreen_ButtonHome, LE_WIDGET_BORDER_NONE);
    HomeScreen_ButtonHome->fn->setReleasedEventCallback(HomeScreen_ButtonHome, event_HomeScreen_ButtonHome_OnReleased);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_ButtonHome);

    HomeScreen_ButtonWiFi = leButtonWidget_New();
    HomeScreen_ButtonWiFi->fn->setPosition(HomeScreen_ButtonWiFi, 2, 174);
    HomeScreen_ButtonWiFi->fn->setSize(HomeScreen_ButtonWiFi, 160, 139);
    HomeScreen_ButtonWiFi->fn->setBackgroundType(HomeScreen_ButtonWiFi, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ButtonWiFi->fn->setBorderType(HomeScreen_ButtonWiFi, LE_WIDGET_BORDER_NONE);
    HomeScreen_ButtonWiFi->fn->setReleasedEventCallback(HomeScreen_ButtonWiFi, event_HomeScreen_ButtonWiFi_OnReleased);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_ButtonWiFi);

    HomeScreen_ButtonSetting = leButtonWidget_New();
    HomeScreen_ButtonSetting->fn->setPosition(HomeScreen_ButtonSetting, 0, 324);
    HomeScreen_ButtonSetting->fn->setSize(HomeScreen_ButtonSetting, 159, 137);
    HomeScreen_ButtonSetting->fn->setBackgroundType(HomeScreen_ButtonSetting, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ButtonSetting->fn->setBorderType(HomeScreen_ButtonSetting, LE_WIDGET_BORDER_NONE);
    HomeScreen_ButtonSetting->fn->setReleasedEventCallback(HomeScreen_ButtonSetting, event_HomeScreen_ButtonSetting_OnReleased);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_ButtonSetting);

    HomeScreen_ButtonFan = leButtonWidget_New();
    HomeScreen_ButtonFan->fn->setPosition(HomeScreen_ButtonFan, 230, 379);
    HomeScreen_ButtonFan->fn->setSize(HomeScreen_ButtonFan, 177, 81);
    HomeScreen_ButtonFan->fn->setBackgroundType(HomeScreen_ButtonFan, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ButtonFan->fn->setBorderType(HomeScreen_ButtonFan, LE_WIDGET_BORDER_NONE);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_ButtonFan);

    HomeScreen_ButtonMode = leButtonWidget_New();
    HomeScreen_ButtonMode->fn->setPosition(HomeScreen_ButtonMode, 424, 379);
    HomeScreen_ButtonMode->fn->setSize(HomeScreen_ButtonMode, 179, 80);
    HomeScreen_ButtonMode->fn->setBackgroundType(HomeScreen_ButtonMode, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ButtonMode->fn->setBorderType(HomeScreen_ButtonMode, LE_WIDGET_BORDER_NONE);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_ButtonMode);

    HomeScreen_ButtonUp = leButtonWidget_New();
    HomeScreen_ButtonUp->fn->setPosition(HomeScreen_ButtonUp, 669, 23);
    HomeScreen_ButtonUp->fn->setSize(HomeScreen_ButtonUp, 112, 114);
    HomeScreen_ButtonUp->fn->setBackgroundType(HomeScreen_ButtonUp, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ButtonUp->fn->setBorderType(HomeScreen_ButtonUp, LE_WIDGET_BORDER_NONE);
    HomeScreen_ButtonUp->fn->setReleasedEventCallback(HomeScreen_ButtonUp, event_HomeScreen_ButtonUp_OnReleased);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_ButtonUp);

    HomeScreen_ButtonDown = leButtonWidget_New();
    HomeScreen_ButtonDown->fn->setPosition(HomeScreen_ButtonDown, 675, 339);
    HomeScreen_ButtonDown->fn->setSize(HomeScreen_ButtonDown, 112, 117);
    HomeScreen_ButtonDown->fn->setBackgroundType(HomeScreen_ButtonDown, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ButtonDown->fn->setBorderType(HomeScreen_ButtonDown, LE_WIDGET_BORDER_NONE);
    HomeScreen_ButtonDown->fn->setReleasedEventCallback(HomeScreen_ButtonDown, event_HomeScreen_ButtonDown_OnReleased);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_ButtonDown);

    HomeScreen_image_imgEllipse = leImageWidget_New();
    HomeScreen_image_imgEllipse->fn->setPosition(HomeScreen_image_imgEllipse, 234, 63);
    HomeScreen_image_imgEllipse->fn->setSize(HomeScreen_image_imgEllipse, 389, 202);
    HomeScreen_image_imgEllipse->fn->setBackgroundType(HomeScreen_image_imgEllipse, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgEllipse->fn->setBorderType(HomeScreen_image_imgEllipse, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgEllipse->fn->setImage(HomeScreen_image_imgEllipse, (leImage*)&figmaImg_imgEllipse);
    HomeScreen_panel_HomeScreen->fn->addChild(HomeScreen_panel_HomeScreen, (leWidget*)HomeScreen_image_imgEllipse);

    HomeScreen_image_imgKnob = leImageWidget_New();
    HomeScreen_image_imgKnob->fn->setPosition(HomeScreen_image_imgKnob, 320, 59);
    HomeScreen_image_imgKnob->fn->setSize(HomeScreen_image_imgKnob, 24, 24);
    HomeScreen_image_imgKnob->fn->setBackgroundType(HomeScreen_image_imgKnob, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_image_imgKnob->fn->setBorderType(HomeScreen_image_imgKnob, LE_WIDGET_BORDER_NONE);
    HomeScreen_image_imgKnob->fn->setImage(HomeScreen_image_imgKnob, (leImage*)&figmaImg_imgKnob);
    HomeScreen_image_imgEllipse->fn->addChild(HomeScreen_image_imgEllipse, (leWidget*)HomeScreen_image_imgKnob);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 620, 480);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    HomeScreen_Panel_SetupScreen = leWidget_New();
    HomeScreen_Panel_SetupScreen->fn->setPosition(HomeScreen_Panel_SetupScreen, 0, 0);
    HomeScreen_Panel_SetupScreen->fn->setSize(HomeScreen_Panel_SetupScreen, 620, 480);
    HomeScreen_Panel_SetupScreen->fn->setEnabled(HomeScreen_Panel_SetupScreen, LE_FALSE);
    HomeScreen_Panel_SetupScreen->fn->setScheme(HomeScreen_Panel_SetupScreen, &panel_whitesmoke);
    root1->fn->addChild(root1, (leWidget*)HomeScreen_Panel_SetupScreen);

    HomeScreen_label_lblSettings = leLabelWidget_New();
    HomeScreen_label_lblSettings->fn->setPosition(HomeScreen_label_lblSettings, 58, 46);
    HomeScreen_label_lblSettings->fn->setSize(HomeScreen_label_lblSettings, 212, 46);
    HomeScreen_label_lblSettings->fn->setScheme(HomeScreen_label_lblSettings, &text_dimgray);
    HomeScreen_label_lblSettings->fn->setBackgroundType(HomeScreen_label_lblSettings, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblSettings->fn->setString(HomeScreen_label_lblSettings, (leString*)&string_figmaStr_lblSettings);
    HomeScreen_Panel_SetupScreen->fn->addChild(HomeScreen_Panel_SetupScreen, (leWidget*)HomeScreen_label_lblSettings);

    HomeScreen_LabelWidget_0 = leLabelWidget_New();
    HomeScreen_LabelWidget_0->fn->setPosition(HomeScreen_LabelWidget_0, 60, 125);
    HomeScreen_LabelWidget_0->fn->setSize(HomeScreen_LabelWidget_0, 468, 23);
    HomeScreen_LabelWidget_0->fn->setScheme(HomeScreen_LabelWidget_0, &text_dimgray);
    HomeScreen_LabelWidget_0->fn->setBackgroundType(HomeScreen_LabelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_LabelWidget_0->fn->setString(HomeScreen_LabelWidget_0, (leString*)&string_figmaStr_lblInstructions);
    HomeScreen_Panel_SetupScreen->fn->addChild(HomeScreen_Panel_SetupScreen, (leWidget*)HomeScreen_LabelWidget_0);

    HomeScreen_label_lblCommision = leLabelWidget_New();
    HomeScreen_label_lblCommision->fn->setPosition(HomeScreen_label_lblCommision, 357, 209);
    HomeScreen_label_lblCommision->fn->setSize(HomeScreen_label_lblCommision, 173, 25);
    HomeScreen_label_lblCommision->fn->setScheme(HomeScreen_label_lblCommision, &text_dimgray);
    HomeScreen_label_lblCommision->fn->setBackgroundType(HomeScreen_label_lblCommision, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblCommision->fn->setString(HomeScreen_label_lblCommision, (leString*)&string_figmaStr_lblCommision);
    HomeScreen_Panel_SetupScreen->fn->addChild(HomeScreen_Panel_SetupScreen, (leWidget*)HomeScreen_label_lblCommision);

    HomeScreen_ImageWidget_0 = leImageWidget_New();
    HomeScreen_ImageWidget_0->fn->setPosition(HomeScreen_ImageWidget_0, 55, 177);
    HomeScreen_ImageWidget_0->fn->setSize(HomeScreen_ImageWidget_0, 255, 266);
    HomeScreen_ImageWidget_0->fn->setBackgroundType(HomeScreen_ImageWidget_0, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ImageWidget_0->fn->setBorderType(HomeScreen_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    HomeScreen_ImageWidget_0->fn->setImage(HomeScreen_ImageWidget_0, (leImage*)&figmaImg_imgQRCode);
    HomeScreen_Panel_SetupScreen->fn->addChild(HomeScreen_Panel_SetupScreen, (leWidget*)HomeScreen_ImageWidget_0);

    HomeScreen_label_lblChangeNetType = leLabelWidget_New();
    HomeScreen_label_lblChangeNetType->fn->setPosition(HomeScreen_label_lblChangeNetType, 358, 282);
    HomeScreen_label_lblChangeNetType->fn->setSize(HomeScreen_label_lblChangeNetType, 193, 25);
    HomeScreen_label_lblChangeNetType->fn->setScheme(HomeScreen_label_lblChangeNetType, &text_dimgray);
    HomeScreen_label_lblChangeNetType->fn->setBackgroundType(HomeScreen_label_lblChangeNetType, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblChangeNetType->fn->setString(HomeScreen_label_lblChangeNetType, (leString*)&string_figmaStr_lblChangeNetType);
    HomeScreen_Panel_SetupScreen->fn->addChild(HomeScreen_Panel_SetupScreen, (leWidget*)HomeScreen_label_lblChangeNetType);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 620, 480);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    HomeScreen_PanelWifiScreen = leWidget_New();
    HomeScreen_PanelWifiScreen->fn->setPosition(HomeScreen_PanelWifiScreen, 0, 0);
    HomeScreen_PanelWifiScreen->fn->setSize(HomeScreen_PanelWifiScreen, 620, 480);
    HomeScreen_PanelWifiScreen->fn->setEnabled(HomeScreen_PanelWifiScreen, LE_FALSE);
    HomeScreen_PanelWifiScreen->fn->setScheme(HomeScreen_PanelWifiScreen, &panel_whitesmoke);
    root2->fn->addChild(root2, (leWidget*)HomeScreen_PanelWifiScreen);

    HomeScreen_label_Wifi_configuration = leLabelWidget_New();
    HomeScreen_label_Wifi_configuration->fn->setPosition(HomeScreen_label_Wifi_configuration, 69, 51);
    HomeScreen_label_Wifi_configuration->fn->setSize(HomeScreen_label_Wifi_configuration, 225, 25);
    HomeScreen_label_Wifi_configuration->fn->setScheme(HomeScreen_label_Wifi_configuration, &text_dimgray);
    HomeScreen_label_Wifi_configuration->fn->setBackgroundType(HomeScreen_label_Wifi_configuration, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_Wifi_configuration->fn->setString(HomeScreen_label_Wifi_configuration, (leString*)&string_figmaStr_Wifi_configuration);
    HomeScreen_PanelWifiScreen->fn->addChild(HomeScreen_PanelWifiScreen, (leWidget*)HomeScreen_label_Wifi_configuration);

    HomeScreen_label_Connected = leLabelWidget_New();
    HomeScreen_label_Connected->fn->setPosition(HomeScreen_label_Connected, 71, 96);
    HomeScreen_label_Connected->fn->setScheme(HomeScreen_label_Connected, &text_dimgray);
    HomeScreen_label_Connected->fn->setBackgroundType(HomeScreen_label_Connected, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_Connected->fn->setString(HomeScreen_label_Connected, (leString*)&string_figmaStr_Connected);
    HomeScreen_PanelWifiScreen->fn->addChild(HomeScreen_PanelWifiScreen, (leWidget*)HomeScreen_label_Connected);

    HomeScreen_ImageWidget_1 = leImageWidget_New();
    HomeScreen_ImageWidget_1->fn->setPosition(HomeScreen_ImageWidget_1, 77, 151);
    HomeScreen_ImageWidget_1->fn->setSize(HomeScreen_ImageWidget_1, 17, 17);
    HomeScreen_ImageWidget_1->fn->setBackgroundType(HomeScreen_ImageWidget_1, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ImageWidget_1->fn->setBorderType(HomeScreen_ImageWidget_1, LE_WIDGET_BORDER_NONE);
    HomeScreen_ImageWidget_1->fn->setImage(HomeScreen_ImageWidget_1, (leImage*)&figmaImg_imgWifiIcon_0);
    HomeScreen_PanelWifiScreen->fn->addChild(HomeScreen_PanelWifiScreen, (leWidget*)HomeScreen_ImageWidget_1);

    HomeScreen_label_lblCurrentWifi = leLabelWidget_New();
    HomeScreen_label_lblCurrentWifi->fn->setPosition(HomeScreen_label_lblCurrentWifi, 25, -3);
    HomeScreen_label_lblCurrentWifi->fn->setSize(HomeScreen_label_lblCurrentWifi, 72, 25);
    HomeScreen_label_lblCurrentWifi->fn->setScheme(HomeScreen_label_lblCurrentWifi, &text_dimgray);
    HomeScreen_label_lblCurrentWifi->fn->setBackgroundType(HomeScreen_label_lblCurrentWifi, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblCurrentWifi->fn->setString(HomeScreen_label_lblCurrentWifi, (leString*)&string_figmaStr_lblCurrentWifi);
    HomeScreen_ImageWidget_1->fn->addChild(HomeScreen_ImageWidget_1, (leWidget*)HomeScreen_label_lblCurrentWifi);

    HomeScreen_ImageWidget_2 = leImageWidget_New();
    HomeScreen_ImageWidget_2->fn->setPosition(HomeScreen_ImageWidget_2, 295, 101);
    HomeScreen_ImageWidget_2->fn->setSize(HomeScreen_ImageWidget_2, 24, 17);
    HomeScreen_ImageWidget_2->fn->setBackgroundType(HomeScreen_ImageWidget_2, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ImageWidget_2->fn->setBorderType(HomeScreen_ImageWidget_2, LE_WIDGET_BORDER_NONE);
    HomeScreen_ImageWidget_2->fn->setImage(HomeScreen_ImageWidget_2, (leImage*)&figmaImg_imgWifiAdd);
    HomeScreen_PanelWifiScreen->fn->addChild(HomeScreen_PanelWifiScreen, (leWidget*)HomeScreen_ImageWidget_2);

    HomeScreen_label_lblScan = leLabelWidget_New();
    HomeScreen_label_lblScan->fn->setPosition(HomeScreen_label_lblScan, 32, -4);
    HomeScreen_label_lblScan->fn->setScheme(HomeScreen_label_lblScan, &text_dimgray);
    HomeScreen_label_lblScan->fn->setBackgroundType(HomeScreen_label_lblScan, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblScan->fn->setString(HomeScreen_label_lblScan, (leString*)&string_figmaStr_lblScan);
    HomeScreen_ImageWidget_2->fn->addChild(HomeScreen_ImageWidget_2, (leWidget*)HomeScreen_label_lblScan);

    HomeScreen_label_lblOtherNetworks = leLabelWidget_New();
    HomeScreen_label_lblOtherNetworks->fn->setPosition(HomeScreen_label_lblOtherNetworks, 272, 148);
    HomeScreen_label_lblOtherNetworks->fn->setSize(HomeScreen_label_lblOtherNetworks, 283, 25);
    HomeScreen_label_lblOtherNetworks->fn->setScheme(HomeScreen_label_lblOtherNetworks, &text_dimgray);
    HomeScreen_label_lblOtherNetworks->fn->setBackgroundType(HomeScreen_label_lblOtherNetworks, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblOtherNetworks->fn->setString(HomeScreen_label_lblOtherNetworks, (leString*)&string_figmaStr_lblOtherNetworks);
    HomeScreen_PanelWifiScreen->fn->addChild(HomeScreen_PanelWifiScreen, (leWidget*)HomeScreen_label_lblOtherNetworks);

    HomeScreen_ImageWidget_3 = leImageWidget_New();
    HomeScreen_ImageWidget_3->fn->setPosition(HomeScreen_ImageWidget_3, 295, 204);
    HomeScreen_ImageWidget_3->fn->setSize(HomeScreen_ImageWidget_3, 17, 17);
    HomeScreen_ImageWidget_3->fn->setBackgroundType(HomeScreen_ImageWidget_3, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ImageWidget_3->fn->setBorderType(HomeScreen_ImageWidget_3, LE_WIDGET_BORDER_NONE);
    HomeScreen_ImageWidget_3->fn->setImage(HomeScreen_ImageWidget_3, (leImage*)&figmaImg_imgWifiIcon_0);
    HomeScreen_PanelWifiScreen->fn->addChild(HomeScreen_PanelWifiScreen, (leWidget*)HomeScreen_ImageWidget_3);

    HomeScreen_label_lblOtherNet1 = leLabelWidget_New();
    HomeScreen_label_lblOtherNet1->fn->setPosition(HomeScreen_label_lblOtherNet1, 28, -3);
    HomeScreen_label_lblOtherNet1->fn->setSize(HomeScreen_label_lblOtherNet1, 158, 25);
    HomeScreen_label_lblOtherNet1->fn->setScheme(HomeScreen_label_lblOtherNet1, &text_dimgray);
    HomeScreen_label_lblOtherNet1->fn->setBackgroundType(HomeScreen_label_lblOtherNet1, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblOtherNet1->fn->setString(HomeScreen_label_lblOtherNet1, (leString*)&string_figmaStr_lblOtherNet1);
    HomeScreen_ImageWidget_3->fn->addChild(HomeScreen_ImageWidget_3, (leWidget*)HomeScreen_label_lblOtherNet1);

    HomeScreen_ImageWidget_4 = leImageWidget_New();
    HomeScreen_ImageWidget_4->fn->setPosition(HomeScreen_ImageWidget_4, 295, 261);
    HomeScreen_ImageWidget_4->fn->setSize(HomeScreen_ImageWidget_4, 17, 17);
    HomeScreen_ImageWidget_4->fn->setBackgroundType(HomeScreen_ImageWidget_4, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ImageWidget_4->fn->setBorderType(HomeScreen_ImageWidget_4, LE_WIDGET_BORDER_NONE);
    HomeScreen_ImageWidget_4->fn->setImage(HomeScreen_ImageWidget_4, (leImage*)&figmaImg_imgWifiIcon_0);
    HomeScreen_PanelWifiScreen->fn->addChild(HomeScreen_PanelWifiScreen, (leWidget*)HomeScreen_ImageWidget_4);

    HomeScreen_label_lblOtherNet2 = leLabelWidget_New();
    HomeScreen_label_lblOtherNet2->fn->setPosition(HomeScreen_label_lblOtherNet2, 29, -5);
    HomeScreen_label_lblOtherNet2->fn->setSize(HomeScreen_label_lblOtherNet2, 181, 26);
    HomeScreen_label_lblOtherNet2->fn->setScheme(HomeScreen_label_lblOtherNet2, &text_dimgray);
    HomeScreen_label_lblOtherNet2->fn->setBackgroundType(HomeScreen_label_lblOtherNet2, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_label_lblOtherNet2->fn->setString(HomeScreen_label_lblOtherNet2, (leString*)&string_figmaStr_lblOtherNet2);
    HomeScreen_ImageWidget_4->fn->addChild(HomeScreen_ImageWidget_4, (leWidget*)HomeScreen_label_lblOtherNet2);

    HomeScreen_ImageWidget_5 = leImageWidget_New();
    HomeScreen_ImageWidget_5->fn->setPosition(HomeScreen_ImageWidget_5, 294, 314);
    HomeScreen_ImageWidget_5->fn->setSize(HomeScreen_ImageWidget_5, 17, 17);
    HomeScreen_ImageWidget_5->fn->setBackgroundType(HomeScreen_ImageWidget_5, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_ImageWidget_5->fn->setBorderType(HomeScreen_ImageWidget_5, LE_WIDGET_BORDER_NONE);
    HomeScreen_ImageWidget_5->fn->setImage(HomeScreen_ImageWidget_5, (leImage*)&figmaImg_imgWifiIcon_0);
    HomeScreen_PanelWifiScreen->fn->addChild(HomeScreen_PanelWifiScreen, (leWidget*)HomeScreen_ImageWidget_5);

    HomeScreen_LabelWidget_1 = leLabelWidget_New();
    HomeScreen_LabelWidget_1->fn->setPosition(HomeScreen_LabelWidget_1, 30, -4);
    HomeScreen_LabelWidget_1->fn->setSize(HomeScreen_LabelWidget_1, 197, 25);
    HomeScreen_LabelWidget_1->fn->setScheme(HomeScreen_LabelWidget_1, &text_dimgray);
    HomeScreen_LabelWidget_1->fn->setBackgroundType(HomeScreen_LabelWidget_1, LE_WIDGET_BACKGROUND_NONE);
    HomeScreen_LabelWidget_1->fn->setString(HomeScreen_LabelWidget_1, (leString*)&string_figmaStr_lblOtherNet3);
    HomeScreen_ImageWidget_5->fn->addChild(HomeScreen_ImageWidget_5, (leWidget*)HomeScreen_LabelWidget_1);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGBA_8888);

    HomeScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_HomeScreen(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);
}

void screenHide_HomeScreen(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    HomeScreen_panel_HomeScreen = NULL;
    HomeScreen_panel_pnlLeftMenu_1 = NULL;
    HomeScreen_panel_pnlUp = NULL;
    HomeScreen_panel_pnlDown = NULL;
    HomeScreen_label_Set_to = NULL;
    HomeScreen_label_lblTargetTempValue = NULL;
    HomeScreen_label_lblTargetDeg = NULL;
    HomeScreen_panel_pnlFan = NULL;
    HomeScreen_image_imgMchp = NULL;
    HomeScreen_panel_pnlTemp = NULL;
    HomeScreen_panel_pnlMode = NULL;
    HomeScreen_panel_pnlTempValues = NULL;
    HomeScreen_ButtonHome = NULL;
    HomeScreen_ButtonWiFi = NULL;
    HomeScreen_ButtonSetting = NULL;
    HomeScreen_ButtonFan = NULL;
    HomeScreen_ButtonMode = NULL;
    HomeScreen_ButtonUp = NULL;
    HomeScreen_ButtonDown = NULL;
    HomeScreen_image_imgEllipse = NULL;
    HomeScreen_image_imgHomeSelect = NULL;
    HomeScreen_image_imgWifi_0 = NULL;
    HomeScreen_image_imgSettings_0 = NULL;
    HomeScreen_image_imgUp = NULL;
    HomeScreen_image_imgDown = NULL;
    HomeScreen_image_imgFan = NULL;
    HomeScreen_label_lblAuto = NULL;
    HomeScreen_label_lblFan = NULL;
    HomeScreen_label_lblTime = NULL;
    HomeScreen_label_lblCurrentTemp = NULL;
    HomeScreen_image_imgCool = NULL;
    HomeScreen_label_lblCool = NULL;
    HomeScreen_label_lblMode = NULL;
    HomeScreen_label_lblTempValue = NULL;
    HomeScreen_label_lblDegree = NULL;
    HomeScreen_image_imgKnob = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    HomeScreen_Panel_SetupScreen = NULL;
    HomeScreen_label_lblSettings = NULL;
    HomeScreen_LabelWidget_0 = NULL;
    HomeScreen_label_lblCommision = NULL;
    HomeScreen_ImageWidget_0 = NULL;
    HomeScreen_label_lblChangeNetType = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    HomeScreen_PanelWifiScreen = NULL;
    HomeScreen_label_Wifi_configuration = NULL;
    HomeScreen_label_Connected = NULL;
    HomeScreen_ImageWidget_1 = NULL;
    HomeScreen_ImageWidget_2 = NULL;
    HomeScreen_label_lblOtherNetworks = NULL;
    HomeScreen_ImageWidget_3 = NULL;
    HomeScreen_ImageWidget_4 = NULL;
    HomeScreen_ImageWidget_5 = NULL;
    HomeScreen_label_lblCurrentWifi = NULL;
    HomeScreen_label_lblScan = NULL;
    HomeScreen_label_lblOtherNet1 = NULL;
    HomeScreen_label_lblOtherNet2 = NULL;
    HomeScreen_LabelWidget_1 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_HomeScreen(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_HomeScreen(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        case 1:
        {
            return root1;
        }
        case 2:
        {
            return root2;
        }
        default:
        {
            return NULL;
        }
    }
}

