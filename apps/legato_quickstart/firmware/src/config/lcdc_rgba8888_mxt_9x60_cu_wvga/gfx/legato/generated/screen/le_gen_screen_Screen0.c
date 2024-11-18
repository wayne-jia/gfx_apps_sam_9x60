#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;
static leWidget* root3;

leWidget* Screen0_default_Layer0_FillPanel;
leImageWidget* Screen0_ImageWidget0;
leImageWidget* Screen0_ImageWidget_1;
leImageWidget* Screen0_ImageWidget_2;
leImageWidget* Screen0_ImageWidget_3;
leImageWidget* Screen0_ImageWidget_4;
leImageWidget* Screen0_ImageWidget_5;
leImageWidget* Screen0_ImageWidget_6;
leImageWidget* Screen0_ImageWidget_7;
leImageWidget* Screen0_ImageWidget_8;
leWidget* Screen0_PanelButton;
leButtonWidget* Screen0_ButtonWidget_0;
leLabelWidget* Screen0_LabelWidget_2;
leLabelWidget* Screen0_LabelWidget_3;
leButtonWidget* Screen0_ButtonWidget_1;
leWidget* Screen0_PanelWidget_3;
leImageWidget* Screen0_ImageWidget_9;
leLabelWidget* Screen0_LabelWidget_0;
leLabelWidget* Screen0_LabelWidget_1;
leWidget* Screen0_PanelWidget_2;
leImageWidget* Screen0_ImageWidget_0;

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

    Screen0_ImageWidget_1 = leImageWidget_New();
    Screen0_ImageWidget_1->fn->setPosition(Screen0_ImageWidget_1, 98, 30);
    Screen0_ImageWidget_1->fn->setSize(Screen0_ImageWidget_1, 40, 40);
    Screen0_ImageWidget_1->fn->setBackgroundType(Screen0_ImageWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_1->fn->setBorderType(Screen0_ImageWidget_1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_1->fn->setImage(Screen0_ImageWidget_1, (leImage*)&home_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_1);

    Screen0_ImageWidget_2 = leImageWidget_New();
    Screen0_ImageWidget_2->fn->setPosition(Screen0_ImageWidget_2, 167, 42);
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
    Screen0_ImageWidget_4->fn->setPosition(Screen0_ImageWidget_4, 163, 144);
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

    Screen0_ButtonWidget_0 = leButtonWidget_New();
    Screen0_ButtonWidget_0->fn->setPosition(Screen0_ButtonWidget_0, 0, 0);
    Screen0_ButtonWidget_0->fn->setSize(Screen0_ButtonWidget_0, 40, 40);
    Screen0_ButtonWidget_0->fn->setBackgroundType(Screen0_ButtonWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0->fn->setBorderType(Screen0_ButtonWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0->fn->setPressedImage(Screen0_ButtonWidget_0, (leImage*)&gear_m);
    Screen0_ButtonWidget_0->fn->setReleasedImage(Screen0_ButtonWidget_0, (leImage*)&gear_m);
    Screen0_ButtonWidget_0->fn->setPressedEventCallback(Screen0_ButtonWidget_0, event_Screen0_ButtonWidget_0_OnPressed);
    Screen0_ImageWidget_5->fn->addChild(Screen0_ImageWidget_5, (leWidget*)Screen0_ButtonWidget_0);

    Screen0_ImageWidget_6 = leImageWidget_New();
    Screen0_ImageWidget_6->fn->setPosition(Screen0_ImageWidget_6, 54, 163);
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
    Screen0_ImageWidget_8->fn->setPosition(Screen0_ImageWidget_8, 37, 45);
    Screen0_ImageWidget_8->fn->setSize(Screen0_ImageWidget_8, 40, 45);
    Screen0_ImageWidget_8->fn->setBackgroundType(Screen0_ImageWidget_8, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_8->fn->setBorderType(Screen0_ImageWidget_8, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_8->fn->setImage(Screen0_ImageWidget_8, (leImage*)&thermo_m);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_8);

    Screen0_PanelButton = leWidget_New();
    Screen0_PanelButton->fn->setPosition(Screen0_PanelButton, 20, 20);
    Screen0_PanelButton->fn->setSize(Screen0_PanelButton, 200, 200);
    Screen0_PanelButton->fn->setBackgroundType(Screen0_PanelButton, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_PanelButton);

    Screen0_LabelWidget_2 = leLabelWidget_New();
    Screen0_LabelWidget_2->fn->setPosition(Screen0_LabelWidget_2, 56, 33);
    Screen0_LabelWidget_2->fn->setSize(Screen0_LabelWidget_2, 79, 26);
    Screen0_LabelWidget_2->fn->setScheme(Screen0_LabelWidget_2, &GreenScheme);
    Screen0_LabelWidget_2->fn->setBackgroundType(Screen0_LabelWidget_2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_2->fn->setString(Screen0_LabelWidget_2, (leString*)&string_set);
    Screen0_PanelButton->fn->addChild(Screen0_PanelButton, (leWidget*)Screen0_LabelWidget_2);

    Screen0_LabelWidget_3 = leLabelWidget_New();
    Screen0_LabelWidget_3->fn->setPosition(Screen0_LabelWidget_3, 49, 79);
    Screen0_LabelWidget_3->fn->setSize(Screen0_LabelWidget_3, 107, 34);
    Screen0_LabelWidget_3->fn->setScheme(Screen0_LabelWidget_3, &GreenScheme);
    Screen0_LabelWidget_3->fn->setBackgroundType(Screen0_LabelWidget_3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_3->fn->setString(Screen0_LabelWidget_3, (leString*)&string_Shezhi);
    Screen0_PanelButton->fn->addChild(Screen0_PanelButton, (leWidget*)Screen0_LabelWidget_3);

    Screen0_ButtonWidget_1 = leButtonWidget_New();
    Screen0_ButtonWidget_1->fn->setPosition(Screen0_ButtonWidget_1, 58, 129);
    Screen0_ButtonWidget_1->fn->setSize(Screen0_ButtonWidget_1, 82, 37);
    Screen0_ButtonWidget_1->fn->setScheme(Screen0_ButtonWidget_1, &GreenScheme);
    Screen0_ButtonWidget_1->fn->setBackgroundType(Screen0_ButtonWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_1->fn->setBorderType(Screen0_ButtonWidget_1, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_1->fn->setString(Screen0_ButtonWidget_1, (leString*)&string_ret);
    Screen0_ButtonWidget_1->fn->setReleasedEventCallback(Screen0_ButtonWidget_1, event_Screen0_ButtonWidget_1_OnReleased);
    Screen0_PanelButton->fn->addChild(Screen0_PanelButton, (leWidget*)Screen0_ButtonWidget_1);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 148, 70);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget_3 = leWidget_New();
    Screen0_PanelWidget_3->fn->setPosition(Screen0_PanelWidget_3, 0, 0);
    Screen0_PanelWidget_3->fn->setSize(Screen0_PanelWidget_3, 148, 70);
    Screen0_PanelWidget_3->fn->setEnabled(Screen0_PanelWidget_3, LE_FALSE);
    Screen0_PanelWidget_3->fn->setScheme(Screen0_PanelWidget_3, &defaultScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_PanelWidget_3);

    Screen0_ImageWidget_9 = leImageWidget_New();
    Screen0_ImageWidget_9->fn->setPosition(Screen0_ImageWidget_9, 0, 0);
    Screen0_ImageWidget_9->fn->setSize(Screen0_ImageWidget_9, 148, 70);
    Screen0_ImageWidget_9->fn->setBackgroundType(Screen0_ImageWidget_9, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_9->fn->setBorderType(Screen0_ImageWidget_9, LE_WIDGET_BORDER_NONE);
    Screen0_PanelWidget_3->fn->addChild(Screen0_PanelWidget_3, (leWidget*)Screen0_ImageWidget_9);

    Screen0_LabelWidget_0 = leLabelWidget_New();
    Screen0_LabelWidget_0->fn->setPosition(Screen0_LabelWidget_0, 0, 0);
    Screen0_LabelWidget_0->fn->setSize(Screen0_LabelWidget_0, 143, 31);
    Screen0_LabelWidget_0->fn->setScheme(Screen0_LabelWidget_0, &defaultScheme);
    Screen0_LabelWidget_0->fn->setString(Screen0_LabelWidget_0, (leString*)&string_Hello);
    Screen0_ImageWidget_9->fn->addChild(Screen0_ImageWidget_9, (leWidget*)Screen0_LabelWidget_0);

    Screen0_LabelWidget_1 = leLabelWidget_New();
    Screen0_LabelWidget_1->fn->setPosition(Screen0_LabelWidget_1, 19, 27);
    Screen0_LabelWidget_1->fn->setSize(Screen0_LabelWidget_1, 107, 33);
    Screen0_LabelWidget_1->fn->setScheme(Screen0_LabelWidget_1, &defaultScheme);
    Screen0_LabelWidget_1->fn->setString(Screen0_LabelWidget_1, (leString*)&string_sc);
    Screen0_ImageWidget_9->fn->addChild(Screen0_ImageWidget_9, (leWidget*)Screen0_LabelWidget_1);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 80, 80);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget_2 = leWidget_New();
    Screen0_PanelWidget_2->fn->setPosition(Screen0_PanelWidget_2, 0, 0);
    Screen0_PanelWidget_2->fn->setSize(Screen0_PanelWidget_2, 80, 80);
    Screen0_PanelWidget_2->fn->setEnabled(Screen0_PanelWidget_2, LE_FALSE);
    Screen0_PanelWidget_2->fn->setBackgroundType(Screen0_PanelWidget_2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->addChild(root2, (leWidget*)Screen0_PanelWidget_2);

    Screen0_ImageWidget_0 = leImageWidget_New();
    Screen0_ImageWidget_0->fn->setPosition(Screen0_ImageWidget_0, 0, 0);
    Screen0_ImageWidget_0->fn->setSize(Screen0_ImageWidget_0, 80, 80);
    Screen0_ImageWidget_0->fn->setBorderType(Screen0_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0->fn->setImage(Screen0_ImageWidget_0, (leImage*)&m);
    Screen0_PanelWidget_2->fn->addChild(Screen0_PanelWidget_2, (leWidget*)Screen0_ImageWidget_0);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGBA_8888);

    // layer 3
    root3 = leWidget_New();
    root3->fn->setSize(root3, 146, 100);
    root3->fn->setBackgroundType(root3, LE_WIDGET_BACKGROUND_NONE);
    root3->fn->setMargins(root3, 0, 0, 0, 0);
    root3->flags |= LE_WIDGET_IGNOREEVENTS;
    root3->flags |= LE_WIDGET_IGNOREPICK;

    leAddRootWidget(root3, 3);
    leSetLayerColorMode(3, LE_COLOR_MODE_RGBA_8888);

    Screen0_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);
    root3->fn->setSize(root3, root3->rect.width, root3->rect.height);
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_default_Layer0_FillPanel = NULL;
    Screen0_ImageWidget0 = NULL;
    Screen0_ImageWidget_1 = NULL;
    Screen0_ImageWidget_2 = NULL;
    Screen0_ImageWidget_3 = NULL;
    Screen0_ImageWidget_4 = NULL;
    Screen0_ImageWidget_5 = NULL;
    Screen0_ImageWidget_6 = NULL;
    Screen0_ImageWidget_7 = NULL;
    Screen0_ImageWidget_8 = NULL;
    Screen0_PanelButton = NULL;
    Screen0_ButtonWidget_0 = NULL;
    Screen0_LabelWidget_2 = NULL;
    Screen0_LabelWidget_3 = NULL;
    Screen0_ButtonWidget_1 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_PanelWidget_3 = NULL;
    Screen0_ImageWidget_9 = NULL;
    Screen0_LabelWidget_0 = NULL;
    Screen0_LabelWidget_1 = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    Screen0_PanelWidget_2 = NULL;
    Screen0_ImageWidget_0 = NULL;

    leRemoveRootWidget(root3, 3);
    leWidget_Delete(root3);
    root3 = NULL;


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
        case 2:
        {
            return root2;
        }
        case 3:
        {
            return root3;
        }
        default:
        {
            return NULL;
        }
    }
}

