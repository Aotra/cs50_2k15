<?php

    // configuration
    require("../includes/config.php"); 

    if($_SERVER["REQUEST_METHOD"] == "GET")
{
        // else render form
        render("quote_form.php",["title" => "Search"]);
}

// else if user reached page via POST (as by submitting form via POST)
else if($_SERVER["REQUEST_METHOD"] == "POST")
{
        $stock = lookup($_POST["symbol"]);
        if($stock == false)
        {
        apologize("the symbol does not exists");
        }
        $positions=[];
        $stock["price"] = number_format($stock["price"] ,4);
        $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "symbol" => $stock["symbol"]
            ];
        render("qf.php",["title" => "quoting","positions"=>$positions]);
       
        }
  ?>
