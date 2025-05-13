#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Splash_BaseFillPanel;
leWidget* Splash_MidLine;
leWidget* Splash_PanelWidget_0;
leWidget* Splash_PanelWidget_0_0;
leLabelWidget* Splash_FreeRTOSLabel;
leImageWidget* Splash_MicrochipLogo_0;
leImageWidget* Splash_MGSLogo;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Splash(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Splash(void)
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

    Splash_BaseFillPanel = leWidget_New();
    Splash_BaseFillPanel->fn->setPosition(Splash_BaseFillPanel, 0, 0);
    Splash_BaseFillPanel->fn->setSize(Splash_BaseFillPanel, 800, 480);
    Splash_BaseFillPanel->fn->setScheme(Splash_BaseFillPanel, &BackScheme);
    root0->fn->addChild(root0, (leWidget*)Splash_BaseFillPanel);

    Splash_MidLine = leWidget_New();
    Splash_MidLine->fn->setPosition(Splash_MidLine, 400, 219);
    Splash_MidLine->fn->setSize(Splash_MidLine, 2, 160);
    Splash_MidLine->fn->setScheme(Splash_MidLine, &EnabledScheme);
    root0->fn->addChild(root0, (leWidget*)Splash_MidLine);

    Splash_PanelWidget_0 = leWidget_New();
    Splash_PanelWidget_0->fn->setPosition(Splash_PanelWidget_0, 79, 273);
    Splash_PanelWidget_0->fn->setSize(Splash_PanelWidget_0, 320, 75);
    Splash_PanelWidget_0->fn->setScheme(Splash_PanelWidget_0, &BackScheme);
    Splash_PanelWidget_0->fn->setBackgroundType(Splash_PanelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Splash_PanelWidget_0);

    Splash_MicrochipLogo_0 = leImageWidget_New();
    Splash_MicrochipLogo_0->fn->setPosition(Splash_MicrochipLogo_0, 26, 16);
    Splash_MicrochipLogo_0->fn->setSize(Splash_MicrochipLogo_0, 220, 40);
    Splash_MicrochipLogo_0->fn->setBackgroundType(Splash_MicrochipLogo_0, LE_WIDGET_BACKGROUND_NONE);
    Splash_MicrochipLogo_0->fn->setBorderType(Splash_MicrochipLogo_0, LE_WIDGET_BORDER_NONE);
    Splash_MicrochipLogo_0->fn->setImage(Splash_MicrochipLogo_0, (leImage*)&mchp_logo_big);
    Splash_PanelWidget_0->fn->addChild(Splash_PanelWidget_0, (leWidget*)Splash_MicrochipLogo_0);

    Splash_PanelWidget_0_0 = leWidget_New();
    Splash_PanelWidget_0_0->fn->setPosition(Splash_PanelWidget_0_0, 404, 254);
    Splash_PanelWidget_0_0->fn->setSize(Splash_PanelWidget_0_0, 320, 120);
    Splash_PanelWidget_0_0->fn->setScheme(Splash_PanelWidget_0_0, &BackScheme);
    Splash_PanelWidget_0_0->fn->setBackgroundType(Splash_PanelWidget_0_0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Splash_PanelWidget_0_0);

    Splash_MGSLogo = leImageWidget_New();
    Splash_MGSLogo->fn->setPosition(Splash_MGSLogo, 46, 27);
    Splash_MGSLogo->fn->setSize(Splash_MGSLogo, 225, 69);
    Splash_MGSLogo->fn->setBackgroundType(Splash_MGSLogo, LE_WIDGET_BACKGROUND_NONE);
    Splash_MGSLogo->fn->setBorderType(Splash_MGSLogo, LE_WIDGET_BORDER_NONE);
    Splash_MGSLogo->fn->setImage(Splash_MGSLogo, (leImage*)&MegaM2);
    Splash_PanelWidget_0_0->fn->addChild(Splash_PanelWidget_0_0, (leWidget*)Splash_MGSLogo);

    Splash_FreeRTOSLabel = leLabelWidget_New();
    Splash_FreeRTOSLabel->fn->setPosition(Splash_FreeRTOSLabel, 688, 454);
    Splash_FreeRTOSLabel->fn->setSize(Splash_FreeRTOSLabel, 111, 25);
    Splash_FreeRTOSLabel->fn->setScheme(Splash_FreeRTOSLabel, &BackScheme);
    Splash_FreeRTOSLabel->fn->setBackgroundType(Splash_FreeRTOSLabel, LE_WIDGET_BACKGROUND_NONE);
    Splash_FreeRTOSLabel->fn->setHAlignment(Splash_FreeRTOSLabel, LE_HALIGN_CENTER);
    Splash_FreeRTOSLabel->fn->setString(Splash_FreeRTOSLabel, (leString*)&string_FreeRTOS);
    root0->fn->addChild(root0, (leWidget*)Splash_FreeRTOSLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    Splash_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Splash(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    Splash_OnUpdate(); // raise event
}

void screenHide_Splash(void)
{
    Splash_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Splash_BaseFillPanel = NULL;
    Splash_MidLine = NULL;
    Splash_PanelWidget_0 = NULL;
    Splash_PanelWidget_0_0 = NULL;
    Splash_FreeRTOSLabel = NULL;
    Splash_MicrochipLogo_0 = NULL;
    Splash_MGSLogo = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Splash(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Splash(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

