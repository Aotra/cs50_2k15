<?php

//configuration
require("../includes/config.php");

//if user reache page via GET (as by clicking a link or via redirect)
if($_SERVER["REQUEST_METHOD"] == "GET")
{
        // else render form
        $rows = query("SELECT shares FROM db WHERE id = ?", $_SESSION["id"]);
        render("sell_form.php",["title" => "Sell","symbols" => $rows]);
}

// else if user reached page via POST (as by submitting form via POST)
else if($_SERVER["REQUEST_METHOD"] == "POST")
{
        if(empty($_POST["symbol"]))        
        {
            apologize("You must provide a symbol.");
        }
        $stock=lookup($_POST["symbol"]);
        if($stock===false)
        {
            apologize("Entered stock name does not exists.");
        }
        else
        {
            $rows = query("SELECT  * FROM db WHERE id = ? AND symbol = ?", $_SESSION["id"],strtoupper($_POST["symbol"]));
            
           if($rows===false)
            {
                   apologize("Entered stock name does not exists in your account."); 
            }
        foreach($rows as $row)
            $value = $stock["price"] * $row["shares"];
            $cost = $stock["price"];
            $query = query("DELETE FROM db WHERE id = ? AND symbol = ? ",$_SESSION["id"],strtoupper($_POST["symbol"]));
            
            if($query === false)
             {
            apologize("Error while selling process.");
            }
            
            $query = query("UPDATE users SET cash=cash+? WHERE id = ? ",$value,$_SESSION["id"]);
             if($query === false)
             {
            apologize("Error while selling process.");
            }
           
              $query = query("INSERT INTO history(id,transaction,date,symbol,shares,cost) VALUES (?,?,NOW(),?,?,?)",$_SESSION["id"],0,strtoupper($_POST["symbol"]),$shares,$cost);
                  
             redirect("/");
            }
            }
            
 ?>       
        
        
        
        
        
        
        
        
        
        
        
            
