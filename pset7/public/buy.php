<?php

//configuration
require("../includes/config.php");

//if user reache page via GET (as by clicking a link or via redirect)
if($_SERVER["REQUEST_METHOD"] == "GET")
{
        // else render form
        render("buy_form.php",["title" => "Buy"]);
}

// else if user reached page via POST (as by submitting form via POST)
else if($_SERVER["REQUEST_METHOD"] == "POST")
{
        if(empty($_POST["code"]))        
        {
            apologize("You must provide a symbol.");
        }
        if(empty($_POST["shares"]) || !is_numeric($_POST["shares"]) || !preg_match("/^\d+$/",$_POST["shares"]))
        {
            apologize("Please provde correct number of shares.");
        }
            $stock=lookup($_POST["code"]);
            if($stock===false)
        {
            apologize("Entered stock name does not exists.");
        }
        
         else
            {
                $value = $stock["price"] * ($_POST["shares"]);
                 $cost = $stock["price"];
                $rows = query("SELECT * FROM users WHERE id = ?",$_SESSION["id"]);
                foreach($rows as $row)
                $cash=$row["cash"];
                if($cash <$value)
                {
                 apologize("You do not have sufficient money.");
                }
                else
            { 
                $query = query("INSERT INTO db(id,symbol,shares) VALUES(?,?,?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",$_SESSION["id"],strtoupper($stock["symbol"]),$_POST["shares"]);
                 if($query === false)
                 {
                    apologize("Error while buying process.");
                 }
                   $query = query("UPDATE users SET cash=cash-? WHERE id = ? ",$value,$_SESSION["id"]);
             if($query === false)
             {
            apologize("Error while buying process.");
            }
            
            
           
            $query = query("INSERT INTO history(id,transaction,date,symbol,shares,cost) VALUES (?,?,NOW(),?,?,?)",$_SESSION["id"],1,strtoupper($stock["symbol"]),$_POST["shares"],$cost);
                 
            redirect("/");
            }
            }
            }
 ?>              
            
            
            
            
            
            
        
        
        
        
        
        
