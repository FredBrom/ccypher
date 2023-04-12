<h1>Cesar's Cypher 1.2</h1>

<p>Cesar cypher is a cypher that encodes and decodes text and digits with the 
Cesar's algorithm of encriptation. The algorithm original form of Cesar's algorithm 
is aply a shift, defined as key, to each letter of the message.</p>
<br>
Example:<br>
Encode 'HELLO WORLD' with 12 shifts:
<br><code>HELLO WORLD -> TQXXA IADXPi</code>
<br>
<p>A better way to encrypt a message by the same algorithm is use a rotary cypher, that is
the key is new for every new letter. This way, in the last example the key would be 12
on the first letter, and 13 for the second one and so on.
We can use any integer as a key, but the value will be 'moduled' for the 26 letter on the alphabet
and the 10 digits. So in the practice it have only 26 discrete keys possyble. </p>

<p>Cesar's Cypher no longer acept input from stdin, but if no output file is provided it will
outut on the stdout.</p>

<p>Now the cypher acepts a string of options for example -rd</p>


<h2>options</h2>
* r - set rotary mode<br>
* d - set decypher mode<br>
* -i <file> - set the input file<br>
* -o <file> - set the output file<br>
* -k <key> - set the key<br>

the input file and key options are mandatory
