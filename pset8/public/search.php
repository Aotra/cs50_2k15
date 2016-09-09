<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
    $str="";
    $flag=0;
    $c=0;
    $s=0;
    for($i=0,$count=strlen($_GET["geo"]);$i<$count;$i++)
    {
    if($_GET["geo"][$i]===",")
    {
    $prams= array_map('trim',explode(",",urldecode($_GET["geo"])));
    $c=1;
    $flag=0;
    break;
    }
    else if($_GET["geo"][$i]===" ")
    {
    $prams= array_map('trim',explode(" ",urldecode($_GET["geo"])));
    $s=1;
    $flag=0;
    break;
    }
    else 
    $flag=1;
    }
    if($flag===1) 
     $prams= array_map('trim',explode(",",urldecode($_GET["geo"])));
    
    
    for($i=0,$count=count($prams);$i<$count;$i++)
    {
     
    
    if($c===1)
    $pars=array_map('trim',explode(" ",urldecode($prams[$i])));
    else if($s===1)
    $pars=array_map('trim',explode(",",urldecode($prams[$i])));
    
        
    for($j=0,$cou=count($pars);$j<$cou;$j++)
    {
   
    
    if($pars[$j]!=="US")
    {
    if(strlen($pars[$j])===2)
    {    
    $rows = query("SELECT *  FROM places WHERE admin_code1 = ? ",$pars[$j]);
    if($rows!==false)
    $pars[$j]=$rows[0]["admin_name1"];      
    }   
    
    $str=$str.$pars[$j]." ";
    }
    else
    continue;
    }
    }
   

    //  search database for places matching $_GET["geo"]
    $places = query("SELECT *  FROM places WHERE MATCH (postal_code,place_name,admin_name1,admin_code1,admin_name2,admin_code2) AGAINST(?)" ,$str );             

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>
