<?php
//configuration
require("../includes/config.php");

        $rows = query("SELECT CASE WHEN transaction = 0 THEN 'SELL' ELSE 'BUY' END transaction,date,symbol,shares,cost FROM history WHERE id=? order by date desc",$_SESSION["id"] );
        if(count($rows) == 0)
        {
        apologize("No user history.");
        }
        render("history.php",["title" => "History","history" => $rows])
        ?>
