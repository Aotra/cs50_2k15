<?php

//configuration
require("../includes/config.php");

//if user reache page via GET (as by clicking a link or via redirect)
if($_SERVER["REQUEST_METHOD"] == "GET")
{
        // else render form
        render("chpw_form.php",["title" => "Change Password"]);
}

// else if user reached page via POST (as by submitting form via POST)
else if($_SERVER["REQUEST_METHOD"] == "POST")

{
 $rows = query("SELECT * FROM users WHERE id = ?",$_SESSION["id"]);
 $row=$rows[0];
        if(empty($_POST["username"]))           
        {
            apologize("You must provide a username.");
        }
        if(crypt($_POST["oldpassword"],$row["hash"]) != $row["hash"] )
         {
            apologize("You must provide the correct previous password.");
        }
        if($_POST["password"]!= $_POST["confirmation"] )
         {
            apologize("Mismatch of passwords.The new password does not match the confirmation.");
        }
        else
        {
        $query= query("UPDATE users SET hash=(?) WHERE username = ? ",crypt($_POST["password"]),$_POST["username"]);
        if($query === false)
        apologize("Sorry internal error.");
        else
        redirect("/");
        }
        }
        
       
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
