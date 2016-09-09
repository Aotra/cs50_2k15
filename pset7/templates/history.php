<div>
    <table class="table table-striped">
    <thead>
    <tr>       
        <td>Transaction</td>
        <td>Date/Time</td>
        <td>Symbol</td>
        <td>Shares</td>
        <td>Price</td>
        </tr>
        </thead>
         <tbody>
        <?php
            
            
            foreach($history as $record)
            {
                print("<tr>");
                print("<td>" . $record["transaction"] ."</td>");
                print("<!--<td>" . $record["date"] ."</td>-->");
                print("<td>" . date('Y-m-d H:i:s',strtotime($record["date"])) ."</td>");
                print("<td>" . $record["symbol"] ."</td>");
                print("<td>" . $record["shares"] ."</td>");
                print("<td>" . number_format($record["cost"],2) ."</td>");
                print("</tr>");
            }
            
               ?> 
                </tbody>   
                 </table>
                 </div>
                 <a href="javascript:history.go(-1);">Back</a>
