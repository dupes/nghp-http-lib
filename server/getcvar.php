<?php

  // phpinfo() 

  if (array_key_exists("hp_duration", $_GET))
    echo "hp_duration = 7200";

  elseif (array_key_exists("hp_reduction", $_GET))
    echo "hp_reduction = 80.5";

  elseif (array_key_exists("hp_W", $_GET))
    echo "hp_W = 2251";

  else
    echo "invalid parameter";

?>
