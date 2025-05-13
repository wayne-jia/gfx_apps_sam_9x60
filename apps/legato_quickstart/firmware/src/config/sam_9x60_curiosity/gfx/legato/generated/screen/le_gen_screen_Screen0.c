#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;

leWidget* Screen0_PanelWidget_0;
leImageWidget* Screen0_mchpLogo;
leLabelWidget* Screen0_LabelWidget_0;
leLabelWidget* Screen0_dynamicLabel;

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
    root0->fn->setSize(root0, LE_DEFAULT_SCREEN_WIDTH, LE_DEFAULT_SCREEN_HEIGHT);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget_0 = leWidget_New();
    Screen0_PanelWidget_0->fn->setPosition(Screen0_PanelWidget_0, 0, 0);
    Screen0_PanelWidget_0->fn->setSize(Screen0_PanelWidget_0, 800, 480);
    Screen0_PanelWidget_0->fn->setScheme(Screen0_PanelWidget_0, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_PanelWidget_0);

    Screen0_mchpLogo = leImageWidget_New();
    Screen0_mchpLogo->fn->setPosition(Screen0_mchpLogo, 9, 7);
    Screen0_mchpLogo->fn->setSize(Screen0_mchpLogo, 120, 28);
    Screen0_mchpLogo->fn->setBackgroundType(Screen0_mchpLogo, LE_WIDGET_BACKGROUND_NONE);
    Screen0_mchpLogo->fn->setBorderType(Screen0_mchpLogo, LE_WIDGET_BORDER_NONE);
    Screen0_mchpLogo->fn->setImage(Screen0_mchpLogo, (leImage*)&mchpLogo_small);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_mchpLogo);

    Screen0_LabelWidget_0 = leLabelWidget_New();
    Screen0_LabelWidget_0->fn->setPosition(Screen0_LabelWidget_0, 9, 435);
    Screen0_LabelWidget_0->fn->setSize(Screen0_LabelWidget_0, 771, 45);
    Screen0_LabelWidget_0->fn->setBackgroundType(Screen0_LabelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_0->fn->setString(Screen0_LabelWidget_0, (leString*)&string_JPG);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_LabelWidget_0);

    Screen0_dynamicLabel = leLabelWidget_New();
    Screen0_dynamicLabel->fn->setPosition(Screen0_dynamicLabel, 160, 3);
    Screen0_dynamicLabel->fn->setSize(Screen0_dynamicLabel, 604, 43);
    Screen0_dynamicLabel->fn->setBackgroundType(Screen0_dynamicLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_dynamicLabel->fn->setString(Screen0_dynamicLabel, (leString*)&string_Reading);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_dynamicLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 800, 360);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

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

    Screen0_PanelWidget_0 = NULL;
    Screen0_mchpLogo = NULL;
    Screen0_LabelWidget_0 = NULL;
    Screen0_dynamicLabel = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;


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

