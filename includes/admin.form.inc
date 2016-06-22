<?php

/**
 * @file
 * Handles the display/submission of the admin settings form for this module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function upitt_extras_admin_settings(array $form, array &$form_state) {
  $form = array(
    'options' => array(
      '#type' => 'fieldset',
      '#title' => t('Options Page'),
      'show_sitejump' => array(
        '#type' => 'checkbox',
        '#title' => t('Show site jump as tab.'),
        '#description' => t('Site jump links allow the administrator to view the same content in the other web sites.'),
        '#default_value' => variable_get('upitt_extras_show_sitejump', 1),
      ),
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    ),
    'reset' => array(
      '#type' => 'submit',
      '#value' => t('Reset to defaults'),
    ),
  );
  return $form;
}

/**
 * Function that sets the Drupal variables with user's input.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 */
function upitt_extras_admin_settings_submit(array $form, array &$form_state) {
  drupal_set_message(t('The settings have been updated!'));
  $id = $form_state['triggering_element']['#id'];
  switch ($id) {
    case 'edit-submit':
      variable_set('upitt_extras_show_sitejump', $form_state['values']['show_sitejump']);
      break;

    case 'edit-reset':
      variable_del('upitt_extras_show_sitejump');
      break;
  }
}
