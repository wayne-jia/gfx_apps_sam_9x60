#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;

leWidget* Screen0_default_Layer0_FillPanel;
leImageWidget* Screen0_ImageWidget0;
leLabelWidget* Screen0_bper;
leWidget* Screen0_PanelWidget_3;
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

    Screen0_bper = leLabelWidget_New();
    Screen0_bper->fn->setPosition(Screen0_bper, 92, 73);
    Screen0_bper->fn->setSize(Screen0_bper, 54, 25);
    Screen0_bper->fn->setScheme(Screen0_bper, &defaultScheme);
    Screen0_bper->fn->setString(Screen0_bper, (leString*)&string_s20);
    root0->fn->addChild(root0, (leWidget*)Screen0_bper);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 136, 46);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget_3 = leWidget_New();
    Screen0_PanelWidget_3->fn->setPosition(Screen0_PanelWidget_3, 0, 0);
    Screen0_PanelWidget_3->fn->setSize(Screen0_PanelWidget_3, 136, 46);
    Screen0_PanelWidget_3->fn->setEnabled(Screen0_PanelWidget_3, LE_FALSE);
    Screen0_PanelWidget_3->fn->setScheme(Screen0_PanelWidget_3, &defaultScheme);
    Screen0_PanelWidget_3->fn->setBackgroundType(Screen0_PanelWidget_3, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_PanelWidget_3);

    Screen0_ImageWidget_0 = leImageWidget_New();
    Screen0_ImageWidget_0->fn->setPosition(Screen0_ImageWidget_0, 0, 0);
    Screen0_ImageWidget_0->fn->setSize(Screen0_ImageWidget_0, 136, 46);
    Screen0_ImageWidget_0->fn->setBackgroundType(Screen0_ImageWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_0->fn->setBorderType(Screen0_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0->fn->setImage(Screen0_ImageWidget_0, (leImage*)&b20);
    root1->fn->addChild(root1, (leWidget*)Screen0_ImageWidget_0);

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
    Screen0_bper = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_PanelWidget_3 = NULL;
    Screen0_ImageWidget_0 = NULL;


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

