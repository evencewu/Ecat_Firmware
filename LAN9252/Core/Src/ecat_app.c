#include "ecat_app.h"

/* CANopen Object Dictionary */
_Objects Obj;

/* Application hook declaration */
void ecatapp();

/* SOES configuration */
static esc_cfg_t config = {
    .user_arg = "/dev/lan9252",
    .use_interrupt = 0,
    .watchdog_cnt = 500,
    .set_defaults_hook = NULL,
    .pre_state_change_hook = NULL,
    .post_state_change_hook = NULL,
    .application_hook = NULL,
    .safeoutput_override = NULL,
    .pre_object_download_hook = NULL,
    .post_object_download_hook = NULL,
    .rxpdo_override = NULL,
    .txpdo_override = NULL,
    .esc_hw_interrupt_enable = NULL,
    .esc_hw_interrupt_disable = NULL,
    .esc_hw_eep_handler = NULL,
    .esc_check_dc_handler = NULL,
};

//---- user application ------------------------------------------------------------------------------

void cb_get_inputs()
{
    // write to slave TxPDO
    // dummy value, so that sawtooth value profile will be seen constantly changing by ecat master
    /*
    Obj.Counter++;
    */
}

void cb_set_outputs()
{
    /*
    // read slave RxPDO
    if (Obj.LedIn)
    {
        STM_EVAL_LEDOn(outPins[0]);
    }
    else
    {
        STM_EVAL_LEDOff(outPins[0]);
    }
    */
}

void EcatInit()
{
    ecat_slv_init(&config);
}

void EcatMainLoop()
{
    ecat_slv();

    if (ESCvar.ALerror)
    {
        // printf("\rAL Error %d\r\n", ESCvar.ALerror);
    }
}
