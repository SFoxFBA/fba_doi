<?php

function batchmintdoi($pid, &$context) {
  module_load_include('module', 'fba_doi', 'fba_doi');
  $fba_doi = new fba_doi();
  $metadata = $fba_doi->registermetadata($pid);
  if ($metadata) {
    $minteddoi = $fba_doi->mintdoi($pid);
    if ($minteddoi !== FALSE) {
      $mintsuccessful = TRUE;
    }
    else {
      $mintsuccessful = FALSE;
    }
  }
  $errormessage = $_SESSION['errormessage'];
  $context['results']['success'][] = array($pid, $mintsuccessful, $errormessage);

  return;
}
