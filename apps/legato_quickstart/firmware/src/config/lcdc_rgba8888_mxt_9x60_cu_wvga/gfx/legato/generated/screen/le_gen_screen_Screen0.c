#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;

leWidget* Screen0_default_Layer0_FillPanel;
leImageWidget* Screen0_ImageWidget0;
leLabelWidget* Screen0_LabelWidget_0;
leImageWidget* Screen0_ImageWidget_1;
leImageWidget* Screen0_ImageWidget_2;
leImageWidget* Screen0_ImageWidget_3;
leImageWidget* Screen0_ImageWidget_4;
leImageWidget* Screen0_ImageWidget_5;
leImageWidget* Screen0_ImageWidget_6;
leImageWidget* Screen0_ImageWidget_7;
leImageWidget* Screen0_ImageWidget_8;
leLabelWidget* Screen0_LabelWidget_1;
leImageWidget* Screen0_ImageWidget_0;
leWidget* Screen0_PanelWidget_1;
leButtonWidget* Screen0_ButtonWidget_0;
leButtonWidget* Screen0_ButtonWidget_1;
leLabelWidget* Screen0_LabelWidget_2;
leLabelWidget* Screen0_LabelWidget_3;

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
    root0->fn->setSize(root0, 240, 240);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_default_Layer0_FillPanel = leWidget_New();
    Screen0_default_Layer0_FillPanel->fn->setPosition(Screen0_default_Layer0_FillPanel, 0, 0);
    Screen0_default_Layer0_FillPanel->fn->setSize(Screen0_default_Layer0_FillPanel, 240, 240);
    Screen0_default_Layer0_FillPanel->fn->setScheme(Screen0_default_Layer0_FillPanel, &LayerScheme);
    Screen0_default_Layer0_FillPanel->fn->setBackgroundType(Screen0_default_Layer0_FillPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_default_Layer0_FillPanel);

    Screen0_ImageWidget0 = leImageWidget_New();
    Screen0_ImageWidget0->fn->setPosition(Screen0_ImageWidget0, 0, 0);
    Screen0_ImageWidget0->fn->setSize(Screen0_ImageWidget0, 240, 240);
    Screen0_ImageWidget0->fn->setBackgroundType(Screen0_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget0->fn->setBorderType(Screen0_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget0->fn->setImage(Screen0_ImageWidget0, (leImage*)&bg240);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget0);

    Screen0_LabelWidget_0 = leLabelWidget_New();
    Screen0_LabelWidget_0->fn->setPosition(Screen0_LabelWidget_0, 55, 114);
    Screen0_LabelWidget_0->fn->setSize(Screen0_LabelWidget_0, 142, 47);
    Screen0_LabelWidget_0->fn->setScheme(Screen0_LabelWidget_0, &defaultScheme);
    Screen0_LabelWidget_0->fn->setBackgroundType(Screen0_LabelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_0->fn->setString(Screen0_LabelWidget_0, (leString*)&string_Hello);
    root0->fn->addChild(root0, (leWidget*)Screen0_LabelWidget_0);

    Screen0_ImageWidget_1 = leImageWidget_New();
    Screen0_ImageWidget_1->fn->setPosition(Screen0_ImageWidget_1, 98, 30);
    Screen0_ImageWidget_1->fn->setSize(Screen0_ImageWidget_1, 40, 40);
    Screen0_ImageWidget_1->fn->setBackgroundType(Screen0_ImageWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_1->fn->setBorderType(Screen0_ImageWidget_1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_1->fn->setImage(Screen0_ImageWidget_1, (leImage*)&home_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_1);

    Screen0_ImageWidget_2 = leImageWidget_New();
    Screen0_ImageWidget_2->fn->setPosition(Screen0_ImageWidget_2, 148, 48);
    Screen0_ImageWidget_2->fn->setSize(Screen0_ImageWidget_2, 40, 40);
    Screen0_ImageWidget_2->fn->setBackgroundType(Screen0_ImageWidget_2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_2->fn->setBorderType(Screen0_ImageWidget_2, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_2->fn->setImage(Screen0_ImageWidget_2, (leImage*)&bulb_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_2);

    Screen0_ImageWidget_3 = leImageWidget_New();
    Screen0_ImageWidget_3->fn->setPosition(Screen0_ImageWidget_3, 173, 97);
    Screen0_ImageWidget_3->fn->setSize(Screen0_ImageWidget_3, 40, 40);
    Screen0_ImageWidget_3->fn->setBackgroundType(Screen0_ImageWidget_3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_3->fn->setBorderType(Screen0_ImageWidget_3, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_3->fn->setImage(Screen0_ImageWidget_3, (leImage*)&clock_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_3);

    Screen0_ImageWidget_4 = leImageWidget_New();
    Screen0_ImageWidget_4->fn->setPosition(Screen0_ImageWidget_4, 154, 147);
    Screen0_ImageWidget_4->fn->setSize(Screen0_ImageWidget_4, 40, 40);
    Screen0_ImageWidget_4->fn->setBackgroundType(Screen0_ImageWidget_4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_4->fn->setBorderType(Screen0_ImageWidget_4, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_4->fn->setImage(Screen0_ImageWidget_4, (leImage*)&fan_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_4);

    Screen0_ImageWidget_5 = leImageWidget_New();
    Screen0_ImageWidget_5->fn->setPosition(Screen0_ImageWidget_5, 104, 172);
    Screen0_ImageWidget_5->fn->setSize(Screen0_ImageWidget_5, 40, 40);
    Screen0_ImageWidget_5->fn->setBackgroundType(Screen0_ImageWidget_5, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_5->fn->setBorderType(Screen0_ImageWidget_5, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_5->fn->setImage(Screen0_ImageWidget_5, (leImage*)&gear_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_5);

    Screen0_ImageWidget_6 = leImageWidget_New();
    Screen0_ImageWidget_6->fn->setPosition(Screen0_ImageWidget_6, 50, 150);
    Screen0_ImageWidget_6->fn->setSize(Screen0_ImageWidget_6, 40, 40);
    Screen0_ImageWidget_6->fn->setBackgroundType(Screen0_ImageWidget_6, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_6->fn->setBorderType(Screen0_ImageWidget_6, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_6->fn->setImage(Screen0_ImageWidget_6, (leImage*)&leaf_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_6);

    Screen0_ImageWidget_7 = leImageWidget_New();
    Screen0_ImageWidget_7->fn->setPosition(Screen0_ImageWidget_7, 32, 102);
    Screen0_ImageWidget_7->fn->setSize(Screen0_ImageWidget_7, 40, 40);
    Screen0_ImageWidget_7->fn->setBackgroundType(Screen0_ImageWidget_7, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_7->fn->setBorderType(Screen0_ImageWidget_7, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_7->fn->setImage(Screen0_ImageWidget_7, (leImage*)&sound_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_7);

    Screen0_ImageWidget_8 = leImageWidget_New();
    Screen0_ImageWidget_8->fn->setPosition(Screen0_ImageWidget_8, 48, 46);
    Screen0_ImageWidget_8->fn->setSize(Screen0_ImageWidget_8, 40, 45);
    Screen0_ImageWidget_8->fn->setBackgroundType(Screen0_ImageWidget_8, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_8->fn->setBorderType(Screen0_ImageWidget_8, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_8->fn->setImage(Screen0_ImageWidget_8, (leImage*)&thermo_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_8);

    Screen0_LabelWidget_1 = leLabelWidget_New();
    Screen0_LabelWidget_1->fn->setPosition(Screen0_LabelWidget_1, 69, 82);
    Screen0_LabelWidget_1->fn->setSize(Screen0_LabelWidget_1, 99, 31);
    Screen0_LabelWidget_1->fn->setScheme(Screen0_LabelWidget_1, &defaultScheme);
    Screen0_LabelWidget_1->fn->setBackgroundType(Screen0_LabelWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_1->fn->setString(Screen0_LabelWidget_1, (leString*)&string_sc);
    root0->fn->addChild(root0, (leWidget*)Screen0_LabelWidget_1);

    Screen0_ImageWidget_0 = leImageWidget_New();
    Screen0_ImageWidget_0->fn->setPosition(Screen0_ImageWidget_0, 80, 80);
    Screen0_ImageWidget_0->fn->setSize(Screen0_ImageWidget_0, 80, 80);
    Screen0_ImageWidget_0->fn->setBackgroundType(Screen0_ImageWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_0->fn->setBorderType(Screen0_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0->fn->setImage(Screen0_ImageWidget_0, (leImage*)&mchp_circle);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 200, 200);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget_1 = leWidget_New();
    Screen0_PanelWidget_1->fn->setPosition(Screen0_PanelWidget_1, 0, 0);
    Screen0_PanelWidget_1->fn->setSize(Screen0_PanelWidget_1, 200, 200);
    Screen0_PanelWidget_1->fn->setBackgroundType(Screen0_PanelWidget_1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_PanelWidget_1);

    Screen0_LabelWidget_2 = leLabelWidget_New();
    Screen0_LabelWidget_2->fn->setPosition(Screen0_LabelWidget_2, 56, 33);
    Screen0_LabelWidget_2->fn->setSize(Screen0_LabelWidget_2, 79, 26);
    Screen0_LabelWidget_2->fn->setScheme(Screen0_LabelWidget_2, &GreenScheme);
    Screen0_LabelWidget_2->fn->setBackgroundType(Screen0_LabelWidget_2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_2->fn->setString(Screen0_LabelWidget_2, (leString*)&string_set);
    Screen0_PanelWidget_1->fn->addChild(Screen0_PanelWidget_1, (leWidget*)Screen0_LabelWidget_2);

    Screen0_LabelWidget_3 = leLabelWidget_New();
    Screen0_LabelWidget_3->fn->setPosition(Screen0_LabelWidget_3, 49, 79);
    Screen0_LabelWidget_3->fn->setSize(Screen0_LabelWidget_3, 107, 34);
    Screen0_LabelWidget_3->fn->setScheme(Screen0_LabelWidget_3, &GreenScheme);
    Screen0_LabelWidget_3->fn->setBackgroundType(Screen0_LabelWidget_3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_3->fn->setString(Screen0_LabelWidget_3, (leString*)&string_Shezhi);
    Screen0_PanelWidget_1->fn->addChild(Screen0_PanelWidget_1, (leWidget*)Screen0_LabelWidget_3);

    Screen0_ButtonWidget_0 = leButtonWidget_New();
    Screen0_ButtonWidget_0->fn->setPosition(Screen0_ButtonWidget_0, 84, 152);
    Screen0_ButtonWidget_0->fn->setSize(Screen0_ButtonWidget_0, 40, 40);
    Screen0_ButtonWidget_0->fn->setBackgroundType(Screen0_ButtonWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0->fn->setBorderType(Screen0_ButtonWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0->fn->setPressedImage(Screen0_ButtonWidget_0, (leImage*)&gear_m);
    Screen0_ButtonWidget_0->fn->setReleasedImage(Screen0_ButtonWidget_0, (leImage*)&gear_m);
    Screen0_ButtonWidget_0->fn->setPressedEventCallback(Screen0_ButtonWidget_0, event_Screen0_ButtonWidget_0_OnPressed);
    root1->fn->addChild(root1, (leWidget*)Screen0_ButtonWidget_0);

    Screen0_ButtonWidget_1 = leButtonWidget_New();
    Screen0_ButtonWidget_1->fn->setPosition(Screen0_ButtonWidget_1, 58, 129);
    Screen0_ButtonWidget_1->fn->setSize(Screen0_ButtonWidget_1, 82, 37);
    Screen0_ButtonWidget_1->fn->setScheme(Screen0_ButtonWidget_1, &GreenScheme);
    Screen0_ButtonWidget_1->fn->setBackgroundType(Screen0_ButtonWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_1->fn->setBorderType(Screen0_ButtonWidget_1, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_1->fn->setString(Screen0_ButtonWidget_1, (leString*)&string_ret);
    Screen0_ButtonWidget_1->fn->setReleasedEventCallback(Screen0_ButtonWidget_1, event_Screen0_ButtonWidget_1_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_ButtonWidget_1);

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
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_default_Layer0_FillPanel = NULL;
    Screen0_ImageWidget0 = NULL;
    Screen0_LabelWidget_0 = NULL;
    Screen0_ImageWidget_1 = NULL;
    Screen0_ImageWidget_2 = NULL;
    Screen0_ImageWidget_3 = NULL;
    Screen0_ImageWidget_4 = NULL;
    Screen0_ImageWidget_5 = NULL;
    Screen0_ImageWidget_6 = NULL;
    Screen0_ImageWidget_7 = NULL;
    Screen0_ImageWidget_8 = NULL;
    Screen0_LabelWidget_1 = NULL;
    Screen0_ImageWidget_0 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_PanelWidget_1 = NULL;
    Screen0_ButtonWidget_0 = NULL;
    Screen0_ButtonWidget_1 = NULL;
    Screen0_LabelWidget_2 = NULL;
    Screen0_LabelWidget_3 = NULL;


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

