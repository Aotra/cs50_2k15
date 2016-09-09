<div>

     <div>
     <table class="table table-hover">
     
      <thead>
    <tr>    
    

<th><a href="quote.php">Quote</a></th>

<th><a href="buy.php">Buy</a></th>

<th><a href="sell.php">Sell</a></th>

<th><a href="record.php">History</a></th>

<th><a href="chpw.php">Change Password</a></th>

<th><a href="logout.php">Log Out</a></th>


        </tr>
        </thead>
        
        
        </table>
</div>                   
    <table class="table table-striped">
    <thead>
    <tr>       
        <td>Symbol</td>
        <td>Shares</td>
        <td>Price</td>
        <td>Total Price</td>
        </tr>
        </thead>
       <tbody>
        <?php
            
            
            foreach($positions as $position)
            {
                print("<tr>");
                print("<td>" . $position["symbol"] ."</td>");
                print("<td>" . $position["shares"] ."</td>");
                print("<td>" . "$" . number_format($position["price"],2) ."</td>");
                print("<td>" . "$" . number_format($position["total"],2) ."</td>");
                print("</tr>");
            }
             $rows = query("SELECT * FROM users WHERE id = ?",$_SESSION["id"]);
             foreach($rows as $row)
             {
             print("<tr>");
                print("<td>" . "CASH" ."</td>");
                print("<td>" . "    " ."</td>");
                print("<td>" . "    " ."</td>");
                print("<td>" . "$" .number_format($row["cash"],2) ."</td>");
                print("</tr>");
            }
               ?> 
      </tbody>                     
    </table>
                   
    
</div>

