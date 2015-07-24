<?php

function batchmintdoi($pid, &$context) {
  $minteddoi = mintdoi($pid);
  if ($minteddoi !== FALSE) {
    $mintsuccessful = TRUE;
  }
  else {
    $mintsuccessful = FALSE;
  }
  $context['results']['success'][] = array($pid, $mintsuccessful);

  return;
}
