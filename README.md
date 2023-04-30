<h1>Cesar's Cypher 1.3</h1>

<p>Cesar cypher is a cypher that encodes and decodes text and digits with the 
Cesar's algorithm of encriptation. The algorithm original form of Cesar's algorithm 
is aply a shift, defined as key, to each letter of the message.</p>
<br>
Example:<br>
Encode 'HELLO WORLD' with 12 shifts:
<br><code>HELLO WORLD -> TQXXA IADXP</code>
<br>
<p>A better way to encrypt a message by the same algorithm is use a rotary cypher, that is
the key is new for every new letter. This way, in the last example the key would be 12
on the first letter, and 13 for the second one and so on.
We can use any integer as a key, but the value will be 'moduled' for the 26 letter on the alphabet
and the 10 digits. So in the practice it have only 26 discrete keys possyble. </p>

<p>All the input or output of the system is made by standard input and output so you can pipe
data in and out of program in any UNIX-like pipe system.</p>

<h2>Examples</h2>
<br><code>$ echo "SECRET MESSAGE" | ./ccypher -k 12 <br> EQODQF YQEEMSQ </code>
<br>
<code>$ ./ccypher -k 14 < <i>input_file.txt</i>
<br>$ ./ccypher -k 14 < <i>input_file.txt</i> > <i> output_file.txt </i>
</code>

<p>Now the cypher acepts a string of options for example -rd</p>



<h2>options</h2>
* r - set rotary mode<br>
* d - set decypher mode<br>
* -k <key> - set the key<br>

