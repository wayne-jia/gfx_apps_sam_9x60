#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;

leWidget* Screen0_BaseFillPanel;
leImageWidget* Screen0_BackSpeedoGaugeImage;
leImageWidget* Screen0_BackTachoGaugeImage;
leLabelWidget* Screen0_rpmLabel;
leImageWidget* Screen0_MicrochipLogo;
leWidget* Screen0_IndicatorsPanel;
leWidget* Screen0_SpeedoValuePanel;
leWidget* Screen0_RangePanel;
leWidget* Screen0_TurnModePanel;
leImageWidget* Screen0_MicrochipLogo_0;
leImageWidget* Screen0_MGSLogo;
leLabelWidget* Screen0_FreeRTOSLabel;
leImageWidget* Screen0_HeadlightIcon;
leImageWidget* Screen0_WarningIcon;
leImageWidget* Screen0_FuelIcon;
leLabelWidget* Screen0_mphLabel;
leLabelWidget* Screen0_SpeedoValueLabel;
leLabelWidget* Screen0_RangeUnitLabel;
leLabelWidget* Screen0_RangeValueLabel;
leImageWidget* Screen0_RangeValueBarBase;
leImageWidget* Screen0_ImageWidget_5;
leLabelWidget* Screen0_GearValueLabel;
leLabelWidget* Screen0_DriveModeLabel;
leImageWidget* Screen0_RangeValueBar;
leImageSequenceWidget* Screen0_RightTurnImageSeq;
leImageSequenceWidget* Screen0_LeftTurnImageSeq;
leImageWidget* Screen0_Directions;
leImageWidget* Screen0_DirectionArrows;
leLabelWidget* Screen0_DistanceLabel;
leLabelWidget* Screen0_DirectionLabel;
leWidget* Screen0_BaseFillPanel_0;
leWidget* Screen0_TouchPanelTacho;
leWidget* Screen0_TouchPanelSpeedo;
leButtonWidget* Screen0_StartButton;
leButtonWidget* Screen0_LeftTurnButton;
leButtonWidget* Screen0_RightTurnButton;
leButtonWidget* Screen0_MetricsButton;
leImageWidget* Screen0_ImageWidget_0_1_0;
leImageWidget* Screen0_ImageWidget_0_0;
leArcWidget* Screen0_TachoArc;
leArcWidget* Screen0_SpeedArc;
leLabelWidget* Screen0_MetricsLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_BaseFillPanel = leWidget_New();
    Screen0_BaseFillPanel->fn->setPosition(Screen0_BaseFillPanel, 0, 0);
    Screen0_BaseFillPanel->fn->setSize(Screen0_BaseFillPanel, 800, 480);
    Screen0_BaseFillPanel->fn->setScheme(Screen0_BaseFillPanel, &BackScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_BaseFillPanel);

    Screen0_BackSpeedoGaugeImage = leImageWidget_New();
    Screen0_BackSpeedoGaugeImage->fn->setPosition(Screen0_BackSpeedoGaugeImage, 343, 113);
    Screen0_BackSpeedoGaugeImage->fn->setSize(Screen0_BackSpeedoGaugeImage, 433, 330);
    Screen0_BackSpeedoGaugeImage->fn->setScheme(Screen0_BackSpeedoGaugeImage, &BackScheme);
    Screen0_BackSpeedoGaugeImage->fn->setBackgroundType(Screen0_BackSpeedoGaugeImage, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BackSpeedoGaugeImage->fn->setBorderType(Screen0_BackSpeedoGaugeImage, LE_WIDGET_BORDER_NONE);
    Screen0_BackSpeedoGaugeImage->fn->setImage(Screen0_BackSpeedoGaugeImage, (leImage*)&speedoback_fill);
    root0->fn->addChild(root0, (leWidget*)Screen0_BackSpeedoGaugeImage);

    Screen0_BackTachoGaugeImage = leImageWidget_New();
    Screen0_BackTachoGaugeImage->fn->setPosition(Screen0_BackTachoGaugeImage, 26, 117);
    Screen0_BackTachoGaugeImage->fn->setSize(Screen0_BackTachoGaugeImage, 279, 329);
    Screen0_BackTachoGaugeImage->fn->setScheme(Screen0_BackTachoGaugeImage, &BackScheme);
    Screen0_BackTachoGaugeImage->fn->setBackgroundType(Screen0_BackTachoGaugeImage, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BackTachoGaugeImage->fn->setBorderType(Screen0_BackTachoGaugeImage, LE_WIDGET_BORDER_NONE);
    Screen0_BackTachoGaugeImage->fn->setImage(Screen0_BackTachoGaugeImage, (leImage*)&rpm_back_fill);
    root0->fn->addChild(root0, (leWidget*)Screen0_BackTachoGaugeImage);

    Screen0_rpmLabel = leLabelWidget_New();
    Screen0_rpmLabel->fn->setPosition(Screen0_rpmLabel, 232, 160);
    Screen0_rpmLabel->fn->setSize(Screen0_rpmLabel, 70, 34);
    Screen0_rpmLabel->fn->setScheme(Screen0_rpmLabel, &BackScheme);
    Screen0_rpmLabel->fn->setBackgroundType(Screen0_rpmLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_rpmLabel->fn->setHAlignment(Screen0_rpmLabel, LE_HALIGN_RIGHT);
    Screen0_rpmLabel->fn->setMargins(Screen0_rpmLabel, 0, 4, 0, 4);
    Screen0_rpmLabel->fn->setString(Screen0_rpmLabel, (leString*)&string_RPMString);
    root0->fn->addChild(root0, (leWidget*)Screen0_rpmLabel);

    Screen0_MicrochipLogo = leImageWidget_New();
    Screen0_MicrochipLogo->fn->setPosition(Screen0_MicrochipLogo, 323, 96);
    Screen0_MicrochipLogo->fn->setSize(Screen0_MicrochipLogo, 138, 25);
    Screen0_MicrochipLogo->fn->setBackgroundType(Screen0_MicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MicrochipLogo->fn->setBorderType(Screen0_MicrochipLogo, LE_WIDGET_BORDER_NONE);
    Screen0_MicrochipLogo->fn->setImage(Screen0_MicrochipLogo, (leImage*)&mchp_logo_small);
    root0->fn->addChild(root0, (leWidget*)Screen0_MicrochipLogo);

    Screen0_IndicatorsPanel = leWidget_New();
    Screen0_IndicatorsPanel->fn->setPosition(Screen0_IndicatorsPanel, 113, 363);
    Screen0_IndicatorsPanel->fn->setSize(Screen0_IndicatorsPanel, 180, 50);
    Screen0_IndicatorsPanel->fn->setBackgroundType(Screen0_IndicatorsPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_IndicatorsPanel);

    Screen0_HeadlightIcon = leImageWidget_New();
    Screen0_HeadlightIcon->fn->setPosition(Screen0_HeadlightIcon, 74, 3);
    Screen0_HeadlightIcon->fn->setSize(Screen0_HeadlightIcon, 42, 42);
    Screen0_HeadlightIcon->fn->setBackgroundType(Screen0_HeadlightIcon, LE_WIDGET_BACKGROUND_NONE);
    Screen0_HeadlightIcon->fn->setBorderType(Screen0_HeadlightIcon, LE_WIDGET_BORDER_NONE);
    Screen0_HeadlightIcon->fn->setImage(Screen0_HeadlightIcon, (leImage*)&HeadlightOn);
    Screen0_IndicatorsPanel->fn->addChild(Screen0_IndicatorsPanel, (leWidget*)Screen0_HeadlightIcon);

    Screen0_WarningIcon = leImageWidget_New();
    Screen0_WarningIcon->fn->setPosition(Screen0_WarningIcon, 14, 4);
    Screen0_WarningIcon->fn->setSize(Screen0_WarningIcon, 40, 40);
    Screen0_WarningIcon->fn->setBackgroundType(Screen0_WarningIcon, LE_WIDGET_BACKGROUND_NONE);
    Screen0_WarningIcon->fn->setBorderType(Screen0_WarningIcon, LE_WIDGET_BORDER_NONE);
    Screen0_WarningIcon->fn->setImage(Screen0_WarningIcon, (leImage*)&WarningOff);
    Screen0_IndicatorsPanel->fn->addChild(Screen0_IndicatorsPanel, (leWidget*)Screen0_WarningIcon);

    Screen0_FuelIcon = leImageWidget_New();
    Screen0_FuelIcon->fn->setPosition(Screen0_FuelIcon, 127, 4);
    Screen0_FuelIcon->fn->setSize(Screen0_FuelIcon, 40, 40);
    Screen0_FuelIcon->fn->setBackgroundType(Screen0_FuelIcon, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FuelIcon->fn->setBorderType(Screen0_FuelIcon, LE_WIDGET_BORDER_NONE);
    Screen0_FuelIcon->fn->setImage(Screen0_FuelIcon, (leImage*)&FuelOn);
    Screen0_IndicatorsPanel->fn->addChild(Screen0_IndicatorsPanel, (leWidget*)Screen0_FuelIcon);

    Screen0_SpeedoValuePanel = leWidget_New();
    Screen0_SpeedoValuePanel->fn->setPosition(Screen0_SpeedoValuePanel, 416, 259);
    Screen0_SpeedoValuePanel->fn->setSize(Screen0_SpeedoValuePanel, 290, 185);
    Screen0_SpeedoValuePanel->fn->setBackgroundType(Screen0_SpeedoValuePanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_SpeedoValuePanel);

    Screen0_mphLabel = leLabelWidget_New();
    Screen0_mphLabel->fn->setPosition(Screen0_mphLabel, 115, 132);
    Screen0_mphLabel->fn->setSize(Screen0_mphLabel, 70, 36);
    Screen0_mphLabel->fn->setScheme(Screen0_mphLabel, &BackScheme);
    Screen0_mphLabel->fn->setBackgroundType(Screen0_mphLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_mphLabel->fn->setHAlignment(Screen0_mphLabel, LE_HALIGN_CENTER);
    Screen0_mphLabel->fn->setMargins(Screen0_mphLabel, 0, 4, 0, 4);
    Screen0_mphLabel->fn->setString(Screen0_mphLabel, (leString*)&string_mphString);
    Screen0_SpeedoValuePanel->fn->addChild(Screen0_SpeedoValuePanel, (leWidget*)Screen0_mphLabel);

    Screen0_SpeedoValueLabel = leLabelWidget_New();
    Screen0_SpeedoValueLabel->fn->setPosition(Screen0_SpeedoValueLabel, 0, 0);
    Screen0_SpeedoValueLabel->fn->setSize(Screen0_SpeedoValueLabel, 294, 131);
    Screen0_SpeedoValueLabel->fn->setScheme(Screen0_SpeedoValueLabel, &RadialGaugeScheme);
    Screen0_SpeedoValueLabel->fn->setBackgroundType(Screen0_SpeedoValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SpeedoValueLabel->fn->setHAlignment(Screen0_SpeedoValueLabel, LE_HALIGN_CENTER);
    Screen0_SpeedoValueLabel->fn->setString(Screen0_SpeedoValueLabel, (leString*)&string_MPH_Default);
    Screen0_SpeedoValuePanel->fn->addChild(Screen0_SpeedoValuePanel, (leWidget*)Screen0_SpeedoValueLabel);

    Screen0_RangePanel = leWidget_New();
    Screen0_RangePanel->fn->setPosition(Screen0_RangePanel, 112, 217);
    Screen0_RangePanel->fn->setSize(Screen0_RangePanel, 190, 140);
    Screen0_RangePanel->fn->setBackgroundType(Screen0_RangePanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_RangePanel);

    Screen0_RangeUnitLabel = leLabelWidget_New();
    Screen0_RangeUnitLabel->fn->setPosition(Screen0_RangeUnitLabel, 102, 86);
    Screen0_RangeUnitLabel->fn->setSize(Screen0_RangeUnitLabel, 78, 27);
    Screen0_RangeUnitLabel->fn->setScheme(Screen0_RangeUnitLabel, &BackScheme);
    Screen0_RangeUnitLabel->fn->setBackgroundType(Screen0_RangeUnitLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_RangeUnitLabel->fn->setMargins(Screen0_RangeUnitLabel, 0, 4, 4, 4);
    Screen0_RangeUnitLabel->fn->setString(Screen0_RangeUnitLabel, (leString*)&string_RangeUnitString);
    Screen0_RangePanel->fn->addChild(Screen0_RangePanel, (leWidget*)Screen0_RangeUnitLabel);

    Screen0_RangeValueLabel = leLabelWidget_New();
    Screen0_RangeValueLabel->fn->setPosition(Screen0_RangeValueLabel, 45, 87);
    Screen0_RangeValueLabel->fn->setSize(Screen0_RangeValueLabel, 56, 25);
    Screen0_RangeValueLabel->fn->setScheme(Screen0_RangeValueLabel, &BackScheme);
    Screen0_RangeValueLabel->fn->setBackgroundType(Screen0_RangeValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_RangeValueLabel->fn->setHAlignment(Screen0_RangeValueLabel, LE_HALIGN_RIGHT);
    Screen0_RangeValueLabel->fn->setMargins(Screen0_RangeValueLabel, 4, 4, 0, 4);
    Screen0_RangeValueLabel->fn->setString(Screen0_RangeValueLabel, (leString*)&string_RangeValueString);
    Screen0_RangePanel->fn->addChild(Screen0_RangePanel, (leWidget*)Screen0_RangeValueLabel);

    Screen0_RangeValueBarBase = leImageWidget_New();
    Screen0_RangeValueBarBase->fn->setPosition(Screen0_RangeValueBarBase, 13, 118);
    Screen0_RangeValueBarBase->fn->setSize(Screen0_RangeValueBarBase, 169, 9);
    Screen0_RangeValueBarBase->fn->setBackgroundType(Screen0_RangeValueBarBase, LE_WIDGET_BACKGROUND_NONE);
    Screen0_RangeValueBarBase->fn->setBorderType(Screen0_RangeValueBarBase, LE_WIDGET_BORDER_NONE);
    Screen0_RangeValueBarBase->fn->setHAlignment(Screen0_RangeValueBarBase, LE_HALIGN_LEFT);
    Screen0_RangeValueBarBase->fn->setMargins(Screen0_RangeValueBarBase, 0, 4, 0, 4);
    Screen0_RangeValueBarBase->fn->setImage(Screen0_RangeValueBarBase, (leImage*)&PurpleProgress);
    Screen0_RangePanel->fn->addChild(Screen0_RangePanel, (leWidget*)Screen0_RangeValueBarBase);

    Screen0_RangeValueBar = leImageWidget_New();
    Screen0_RangeValueBar->fn->setPosition(Screen0_RangeValueBar, 0, 0);
    Screen0_RangeValueBar->fn->setSize(Screen0_RangeValueBar, 100, 9);
    Screen0_RangeValueBar->fn->setBackgroundType(Screen0_RangeValueBar, LE_WIDGET_BACKGROUND_NONE);
    Screen0_RangeValueBar->fn->setBorderType(Screen0_RangeValueBar, LE_WIDGET_BORDER_NONE);
    Screen0_RangeValueBar->fn->setHAlignment(Screen0_RangeValueBar, LE_HALIGN_LEFT);
    Screen0_RangeValueBar->fn->setMargins(Screen0_RangeValueBar, 0, 4, 4, 0);
    Screen0_RangeValueBar->fn->setImage(Screen0_RangeValueBar, (leImage*)&OrangeProgress);
    Screen0_RangeValueBarBase->fn->addChild(Screen0_RangeValueBarBase, (leWidget*)Screen0_RangeValueBar);

    Screen0_ImageWidget_5 = leImageWidget_New();
    Screen0_ImageWidget_5->fn->setPosition(Screen0_ImageWidget_5, 24, 88);
    Screen0_ImageWidget_5->fn->setSize(Screen0_ImageWidget_5, 24, 23);
    Screen0_ImageWidget_5->fn->setBackgroundType(Screen0_ImageWidget_5, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_5->fn->setBorderType(Screen0_ImageWidget_5, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_5->fn->setImage(Screen0_ImageWidget_5, (leImage*)&battery_charging_full);
    Screen0_RangePanel->fn->addChild(Screen0_RangePanel, (leWidget*)Screen0_ImageWidget_5);

    Screen0_GearValueLabel = leLabelWidget_New();
    Screen0_GearValueLabel->fn->setPosition(Screen0_GearValueLabel, 42, -1);
    Screen0_GearValueLabel->fn->setSize(Screen0_GearValueLabel, 70, 76);
    Screen0_GearValueLabel->fn->setScheme(Screen0_GearValueLabel, &BackScheme);
    Screen0_GearValueLabel->fn->setBackgroundType(Screen0_GearValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_GearValueLabel->fn->setHAlignment(Screen0_GearValueLabel, LE_HALIGN_RIGHT);
    Screen0_GearValueLabel->fn->setMargins(Screen0_GearValueLabel, 4, 4, 0, 4);
    Screen0_GearValueLabel->fn->setString(Screen0_GearValueLabel, (leString*)&string_GearNumber);
    Screen0_RangePanel->fn->addChild(Screen0_RangePanel, (leWidget*)Screen0_GearValueLabel);

    Screen0_DriveModeLabel = leLabelWidget_New();
    Screen0_DriveModeLabel->fn->setPosition(Screen0_DriveModeLabel, 119, 35);
    Screen0_DriveModeLabel->fn->setSize(Screen0_DriveModeLabel, 70, 34);
    Screen0_DriveModeLabel->fn->setScheme(Screen0_DriveModeLabel, &BackScheme);
    Screen0_DriveModeLabel->fn->setBackgroundType(Screen0_DriveModeLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DriveModeLabel->fn->setMargins(Screen0_DriveModeLabel, 0, 4, 0, 4);
    Screen0_DriveModeLabel->fn->setString(Screen0_DriveModeLabel, (leString*)&string_ModeString);
    Screen0_RangePanel->fn->addChild(Screen0_RangePanel, (leWidget*)Screen0_DriveModeLabel);

    Screen0_TurnModePanel = leWidget_New();
    Screen0_TurnModePanel->fn->setPosition(Screen0_TurnModePanel, 14, -1);
    Screen0_TurnModePanel->fn->setSize(Screen0_TurnModePanel, 780, 100);
    Screen0_TurnModePanel->fn->setBackgroundType(Screen0_TurnModePanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_TurnModePanel);

    Screen0_RightTurnImageSeq = leImageSequenceWidget_New();
    Screen0_RightTurnImageSeq->fn->setPosition(Screen0_RightTurnImageSeq, 665, 4);
    Screen0_RightTurnImageSeq->fn->setSize(Screen0_RightTurnImageSeq, 92, 92);
    Screen0_RightTurnImageSeq->fn->setBackgroundType(Screen0_RightTurnImageSeq, LE_WIDGET_BACKGROUND_NONE);
    Screen0_RightTurnImageSeq->fn->setRepeat(Screen0_RightTurnImageSeq, LE_TRUE);
    Screen0_RightTurnImageSeq->fn->setImageCount(Screen0_RightTurnImageSeq, 2);
    Screen0_RightTurnImageSeq->fn->setImage(Screen0_RightTurnImageSeq, 0, &RightTurnOff);
    Screen0_RightTurnImageSeq->fn->setImageDelay(Screen0_RightTurnImageSeq, 0, 1000);
    Screen0_RightTurnImageSeq->fn->setImage(Screen0_RightTurnImageSeq, 1, &RightTurnOn);
    Screen0_RightTurnImageSeq->fn->setImageDelay(Screen0_RightTurnImageSeq, 1, 1000);
    Screen0_TurnModePanel->fn->addChild(Screen0_TurnModePanel, (leWidget*)Screen0_RightTurnImageSeq);

    Screen0_LeftTurnImageSeq = leImageSequenceWidget_New();
    Screen0_LeftTurnImageSeq->fn->setPosition(Screen0_LeftTurnImageSeq, 16, 5);
    Screen0_LeftTurnImageSeq->fn->setSize(Screen0_LeftTurnImageSeq, 92, 92);
    Screen0_LeftTurnImageSeq->fn->setBackgroundType(Screen0_LeftTurnImageSeq, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LeftTurnImageSeq->fn->setRepeat(Screen0_LeftTurnImageSeq, LE_TRUE);
    Screen0_LeftTurnImageSeq->fn->setImageCount(Screen0_LeftTurnImageSeq, 2);
    Screen0_LeftTurnImageSeq->fn->setImage(Screen0_LeftTurnImageSeq, 0, &LeftTurnOff);
    Screen0_LeftTurnImageSeq->fn->setImageDelay(Screen0_LeftTurnImageSeq, 0, 1000);
    Screen0_LeftTurnImageSeq->fn->setImage(Screen0_LeftTurnImageSeq, 1, &LeftTurnOn);
    Screen0_LeftTurnImageSeq->fn->setImageDelay(Screen0_LeftTurnImageSeq, 1, 1000);
    Screen0_TurnModePanel->fn->addChild(Screen0_TurnModePanel, (leWidget*)Screen0_LeftTurnImageSeq);

    Screen0_Directions = leImageWidget_New();
    Screen0_Directions->fn->setPosition(Screen0_Directions, 225, 11);
    Screen0_Directions->fn->setSize(Screen0_Directions, 322, 77);
    Screen0_Directions->fn->setBackgroundType(Screen0_Directions, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Directions->fn->setBorderType(Screen0_Directions, LE_WIDGET_BORDER_NONE);
    Screen0_Directions->fn->setImage(Screen0_Directions, (leImage*)&DirectionsBox);
    Screen0_TurnModePanel->fn->addChild(Screen0_TurnModePanel, (leWidget*)Screen0_Directions);

    Screen0_DirectionArrows = leImageWidget_New();
    Screen0_DirectionArrows->fn->setPosition(Screen0_DirectionArrows, 2, 3);
    Screen0_DirectionArrows->fn->setSize(Screen0_DirectionArrows, 73, 73);
    Screen0_DirectionArrows->fn->setBackgroundType(Screen0_DirectionArrows, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DirectionArrows->fn->setBorderType(Screen0_DirectionArrows, LE_WIDGET_BORDER_NONE);
    Screen0_DirectionArrows->fn->setImage(Screen0_DirectionArrows, (leImage*)&turn_right);
    Screen0_Directions->fn->addChild(Screen0_Directions, (leWidget*)Screen0_DirectionArrows);

    Screen0_DistanceLabel = leLabelWidget_New();
    Screen0_DistanceLabel->fn->setPosition(Screen0_DistanceLabel, 75, 12);
    Screen0_DistanceLabel->fn->setSize(Screen0_DistanceLabel, 243, 25);
    Screen0_DistanceLabel->fn->setScheme(Screen0_DistanceLabel, &BackScheme);
    Screen0_DistanceLabel->fn->setBackgroundType(Screen0_DistanceLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DistanceLabel->fn->setString(Screen0_DistanceLabel, (leString*)&string_DistanceStringRight);
    Screen0_Directions->fn->addChild(Screen0_Directions, (leWidget*)Screen0_DistanceLabel);

    Screen0_DirectionLabel = leLabelWidget_New();
    Screen0_DirectionLabel->fn->setPosition(Screen0_DirectionLabel, 75, 41);
    Screen0_DirectionLabel->fn->setSize(Screen0_DirectionLabel, 243, 25);
    Screen0_DirectionLabel->fn->setScheme(Screen0_DirectionLabel, &BackScheme);
    Screen0_DirectionLabel->fn->setBackgroundType(Screen0_DirectionLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DirectionLabel->fn->setString(Screen0_DirectionLabel, (leString*)&string_DirectionStringRight);
    Screen0_Directions->fn->addChild(Screen0_Directions, (leWidget*)Screen0_DirectionLabel);

    Screen0_MicrochipLogo_0 = leImageWidget_New();
    Screen0_MicrochipLogo_0->fn->setPosition(Screen0_MicrochipLogo_0, 105, 289);
    Screen0_MicrochipLogo_0->fn->setSize(Screen0_MicrochipLogo_0, 220, 40);
    Screen0_MicrochipLogo_0->fn->setBackgroundType(Screen0_MicrochipLogo_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MicrochipLogo_0->fn->setBorderType(Screen0_MicrochipLogo_0, LE_WIDGET_BORDER_NONE);
    Screen0_MicrochipLogo_0->fn->setImage(Screen0_MicrochipLogo_0, (leImage*)&mchp_logo_big);
    root0->fn->addChild(root0, (leWidget*)Screen0_MicrochipLogo_0);

    Screen0_MGSLogo = leImageWidget_New();
    Screen0_MGSLogo->fn->setPosition(Screen0_MGSLogo, 450, 281);
    Screen0_MGSLogo->fn->setSize(Screen0_MGSLogo, 225, 69);
    Screen0_MGSLogo->fn->setBackgroundType(Screen0_MGSLogo, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MGSLogo->fn->setBorderType(Screen0_MGSLogo, LE_WIDGET_BORDER_NONE);
    Screen0_MGSLogo->fn->setImage(Screen0_MGSLogo, (leImage*)&MegaM2);
    root0->fn->addChild(root0, (leWidget*)Screen0_MGSLogo);

    Screen0_FreeRTOSLabel = leLabelWidget_New();
    Screen0_FreeRTOSLabel->fn->setPosition(Screen0_FreeRTOSLabel, 688, 454);
    Screen0_FreeRTOSLabel->fn->setSize(Screen0_FreeRTOSLabel, 111, 25);
    Screen0_FreeRTOSLabel->fn->setScheme(Screen0_FreeRTOSLabel, &StatsScheme);
    Screen0_FreeRTOSLabel->fn->setBackgroundType(Screen0_FreeRTOSLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FreeRTOSLabel->fn->setHAlignment(Screen0_FreeRTOSLabel, LE_HALIGN_CENTER);
    Screen0_FreeRTOSLabel->fn->setString(Screen0_FreeRTOSLabel, (leString*)&string_FreeRTOS);
    root0->fn->addChild(root0, (leWidget*)Screen0_FreeRTOSLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 800, 480);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_BaseFillPanel_0 = leWidget_New();
    Screen0_BaseFillPanel_0->fn->setPosition(Screen0_BaseFillPanel_0, 0, 0);
    Screen0_BaseFillPanel_0->fn->setSize(Screen0_BaseFillPanel_0, 800, 480);
    Screen0_BaseFillPanel_0->fn->setEnabled(Screen0_BaseFillPanel_0, LE_FALSE);
    Screen0_BaseFillPanel_0->fn->setScheme(Screen0_BaseFillPanel_0, &ClearScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_BaseFillPanel_0);

    Screen0_ImageWidget_0_1_0 = leImageWidget_New();
    Screen0_ImageWidget_0_1_0->fn->setPosition(Screen0_ImageWidget_0_1_0, 27, 117);
    Screen0_ImageWidget_0_1_0->fn->setSize(Screen0_ImageWidget_0_1_0, 279, 329);
    Screen0_ImageWidget_0_1_0->fn->setScheme(Screen0_ImageWidget_0_1_0, &ClearScheme);
    Screen0_ImageWidget_0_1_0->fn->setBackgroundType(Screen0_ImageWidget_0_1_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_0_1_0->fn->setBorderType(Screen0_ImageWidget_0_1_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0_1_0->fn->setImage(Screen0_ImageWidget_0_1_0, (leImage*)&rpm_front);
    Screen0_BaseFillPanel_0->fn->addChild(Screen0_BaseFillPanel_0, (leWidget*)Screen0_ImageWidget_0_1_0);

    Screen0_TachoArc = leArcWidget_New();
    Screen0_TachoArc->fn->setPosition(Screen0_TachoArc, -11, -11);
    Screen0_TachoArc->fn->setSize(Screen0_TachoArc, 448, 452);
    Screen0_TachoArc->fn->setAlphaAmount(Screen0_TachoArc, 0);
    Screen0_TachoArc->fn->setScheme(Screen0_TachoArc, &RadialGaugeScheme);
    Screen0_TachoArc->fn->setVAlignment(Screen0_TachoArc, LE_VALIGN_TOP);
    Screen0_TachoArc->fn->setRadius(Screen0_TachoArc, 205);
    Screen0_TachoArc->fn->setStartAngle(Screen0_TachoArc, 70);
    Screen0_TachoArc->fn->setThickness(Screen0_TachoArc, 25);
    Screen0_ImageWidget_0_1_0->fn->addChild(Screen0_ImageWidget_0_1_0, (leWidget*)Screen0_TachoArc);

    Screen0_ImageWidget_0_0 = leImageWidget_New();
    Screen0_ImageWidget_0_0->fn->setPosition(Screen0_ImageWidget_0_0, 343, 113);
    Screen0_ImageWidget_0_0->fn->setSize(Screen0_ImageWidget_0_0, 433, 330);
    Screen0_ImageWidget_0_0->fn->setScheme(Screen0_ImageWidget_0_0, &ClearScheme);
    Screen0_ImageWidget_0_0->fn->setBackgroundType(Screen0_ImageWidget_0_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_0_0->fn->setBorderType(Screen0_ImageWidget_0_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0_0->fn->setImage(Screen0_ImageWidget_0_0, (leImage*)&speedofront);
    Screen0_BaseFillPanel_0->fn->addChild(Screen0_BaseFillPanel_0, (leWidget*)Screen0_ImageWidget_0_0);

    Screen0_SpeedArc = leArcWidget_New();
    Screen0_SpeedArc->fn->setPosition(Screen0_SpeedArc, -5, -4);
    Screen0_SpeedArc->fn->setSize(Screen0_SpeedArc, 440, 440);
    Screen0_SpeedArc->fn->setScheme(Screen0_SpeedArc, &RadialGaugeScheme);
    Screen0_SpeedArc->fn->setVAlignment(Screen0_SpeedArc, LE_VALIGN_TOP);
    Screen0_SpeedArc->fn->setMargins(Screen0_SpeedArc, 0, 0, 0, 0);
    Screen0_SpeedArc->fn->setRadius(Screen0_SpeedArc, 182);
    Screen0_SpeedArc->fn->setStartAngle(Screen0_SpeedArc, -32);
    Screen0_SpeedArc->fn->setCenterAngle(Screen0_SpeedArc, 360);
    Screen0_SpeedArc->fn->setThickness(Screen0_SpeedArc, 76);
    Screen0_ImageWidget_0_0->fn->addChild(Screen0_ImageWidget_0_0, (leWidget*)Screen0_SpeedArc);

    Screen0_TouchPanelTacho = leWidget_New();
    Screen0_TouchPanelTacho->fn->setPosition(Screen0_TouchPanelTacho, 27, 117);
    Screen0_TouchPanelTacho->fn->setSize(Screen0_TouchPanelTacho, 432, 432);
    Screen0_TouchPanelTacho->fn->setBackgroundType(Screen0_TouchPanelTacho, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_TouchPanelTacho);

    Screen0_TouchPanelSpeedo = leWidget_New();
    Screen0_TouchPanelSpeedo->fn->setPosition(Screen0_TouchPanelSpeedo, 343, 113);
    Screen0_TouchPanelSpeedo->fn->setSize(Screen0_TouchPanelSpeedo, 432, 432);
    Screen0_TouchPanelSpeedo->fn->setBackgroundType(Screen0_TouchPanelSpeedo, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_TouchPanelSpeedo);

    Screen0_StartButton = leButtonWidget_New();
    Screen0_StartButton->fn->setPosition(Screen0_StartButton, 173, 430);
    Screen0_StartButton->fn->setSize(Screen0_StartButton, 100, 39);
    Screen0_StartButton->fn->setScheme(Screen0_StartButton, &DisabledScheme);
    Screen0_StartButton->fn->setBackgroundType(Screen0_StartButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_StartButton->fn->setBorderType(Screen0_StartButton, LE_WIDGET_BORDER_NONE);
    Screen0_StartButton->fn->setString(Screen0_StartButton, (leString*)&string_DemoOff);
    Screen0_StartButton->fn->setPressedEventCallback(Screen0_StartButton, event_Screen0_StartButton_OnPressed);
    Screen0_StartButton->fn->setReleasedEventCallback(Screen0_StartButton, event_Screen0_StartButton_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_StartButton);

    Screen0_LeftTurnButton = leButtonWidget_New();
    Screen0_LeftTurnButton->fn->setPosition(Screen0_LeftTurnButton, 0, 0);
    Screen0_LeftTurnButton->fn->setSize(Screen0_LeftTurnButton, 150, 100);
    Screen0_LeftTurnButton->fn->setBackgroundType(Screen0_LeftTurnButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LeftTurnButton->fn->setBorderType(Screen0_LeftTurnButton, LE_WIDGET_BORDER_NONE);
    Screen0_LeftTurnButton->fn->setToggleable(Screen0_LeftTurnButton, LE_TRUE);
    Screen0_LeftTurnButton->fn->setPressedOffset(Screen0_LeftTurnButton, 0);
    Screen0_LeftTurnButton->fn->setPressedEventCallback(Screen0_LeftTurnButton, event_Screen0_LeftTurnButton_OnPressed);
    Screen0_LeftTurnButton->fn->setReleasedEventCallback(Screen0_LeftTurnButton, event_Screen0_LeftTurnButton_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_LeftTurnButton);

    Screen0_RightTurnButton = leButtonWidget_New();
    Screen0_RightTurnButton->fn->setPosition(Screen0_RightTurnButton, 650, 0);
    Screen0_RightTurnButton->fn->setSize(Screen0_RightTurnButton, 150, 100);
    Screen0_RightTurnButton->fn->setBackgroundType(Screen0_RightTurnButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_RightTurnButton->fn->setBorderType(Screen0_RightTurnButton, LE_WIDGET_BORDER_NONE);
    Screen0_RightTurnButton->fn->setToggleable(Screen0_RightTurnButton, LE_TRUE);
    Screen0_RightTurnButton->fn->setPressedOffset(Screen0_RightTurnButton, 0);
    Screen0_RightTurnButton->fn->setPressedEventCallback(Screen0_RightTurnButton, event_Screen0_RightTurnButton_OnPressed);
    Screen0_RightTurnButton->fn->setReleasedEventCallback(Screen0_RightTurnButton, event_Screen0_RightTurnButton_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_RightTurnButton);

    Screen0_MetricsButton = leButtonWidget_New();
    Screen0_MetricsButton->fn->setPosition(Screen0_MetricsButton, 465, 435);
    Screen0_MetricsButton->fn->setSize(Screen0_MetricsButton, 200, 37);
    Screen0_MetricsButton->fn->setScheme(Screen0_MetricsButton, &StatsScheme);
    Screen0_MetricsButton->fn->setBackgroundType(Screen0_MetricsButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MetricsButton->fn->setBorderType(Screen0_MetricsButton, LE_WIDGET_BORDER_NONE);
    Screen0_MetricsButton->fn->setToggleable(Screen0_MetricsButton, LE_TRUE);
    Screen0_MetricsButton->fn->setString(Screen0_MetricsButton, (leString*)&string_StatsString);
    Screen0_MetricsButton->fn->setPressedEventCallback(Screen0_MetricsButton, event_Screen0_MetricsButton_OnPressed);
    Screen0_MetricsButton->fn->setReleasedEventCallback(Screen0_MetricsButton, event_Screen0_MetricsButton_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_MetricsButton);

    Screen0_MetricsLabel = leLabelWidget_New();
    Screen0_MetricsLabel->fn->setPosition(Screen0_MetricsLabel, 12, 4);
    Screen0_MetricsLabel->fn->setSize(Screen0_MetricsLabel, 174, 29);
    Screen0_MetricsLabel->fn->setVisible(Screen0_MetricsLabel, LE_FALSE);
    Screen0_MetricsLabel->fn->setScheme(Screen0_MetricsLabel, &BackScheme);
    Screen0_MetricsLabel->fn->setHAlignment(Screen0_MetricsLabel, LE_HALIGN_CENTER);
    Screen0_MetricsLabel->fn->setString(Screen0_MetricsLabel, (leString*)&string_MetricsString);
    Screen0_MetricsButton->fn->addChild(Screen0_MetricsButton, (leWidget*)Screen0_MetricsLabel);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    Screen0_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);

    Screen0_OnUpdate(); // raise event
}

void screenHide_Screen0(void)
{
    Screen0_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_BaseFillPanel = NULL;
    Screen0_BackSpeedoGaugeImage = NULL;
    Screen0_BackTachoGaugeImage = NULL;
    Screen0_rpmLabel = NULL;
    Screen0_MicrochipLogo = NULL;
    Screen0_IndicatorsPanel = NULL;
    Screen0_SpeedoValuePanel = NULL;
    Screen0_RangePanel = NULL;
    Screen0_TurnModePanel = NULL;
    Screen0_MicrochipLogo_0 = NULL;
    Screen0_MGSLogo = NULL;
    Screen0_FreeRTOSLabel = NULL;
    Screen0_HeadlightIcon = NULL;
    Screen0_WarningIcon = NULL;
    Screen0_FuelIcon = NULL;
    Screen0_mphLabel = NULL;
    Screen0_SpeedoValueLabel = NULL;
    Screen0_RangeUnitLabel = NULL;
    Screen0_RangeValueLabel = NULL;
    Screen0_RangeValueBarBase = NULL;
    Screen0_ImageWidget_5 = NULL;
    Screen0_GearValueLabel = NULL;
    Screen0_DriveModeLabel = NULL;
    Screen0_RangeValueBar = NULL;
    Screen0_RightTurnImageSeq = NULL;
    Screen0_LeftTurnImageSeq = NULL;
    Screen0_Directions = NULL;
    Screen0_DirectionArrows = NULL;
    Screen0_DistanceLabel = NULL;
    Screen0_DirectionLabel = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_BaseFillPanel_0 = NULL;
    Screen0_TouchPanelTacho = NULL;
    Screen0_TouchPanelSpeedo = NULL;
    Screen0_StartButton = NULL;
    Screen0_LeftTurnButton = NULL;
    Screen0_RightTurnButton = NULL;
    Screen0_MetricsButton = NULL;
    Screen0_ImageWidget_0_1_0 = NULL;
    Screen0_ImageWidget_0_0 = NULL;
    Screen0_TachoArc = NULL;
    Screen0_SpeedArc = NULL;
    Screen0_MetricsLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen0(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
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
        default:
        {
            return NULL;
        }
    }
}

