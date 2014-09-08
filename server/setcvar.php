<?php

  // phpinfo() 

  if (array_key_exists("hp_duration", $_GET))
  {
    $key = "hp_duration";
    $min = 0;
    $max = 32767;
  }
  elseif (array_key_exists("hp_reduction", $_GET))
  {
    $key = "hp_reduction";
    $min = 0;
    $max = 100;
  }
  else
  {
    echo "invalid parameter";
    return;
  }

  // $value = $_GET[$key];
  $values = explode("&", $_SERVER["QUERY_STRING"]);
  $value = $values[count($values) -1];

  $convertedValue = floatval($value);
  
  if ($convertedValue >= $min && $convertedValue <= $max)
    echo $key . " = " . $value . " OK";
  else
    echo "variable out of range";
?>
