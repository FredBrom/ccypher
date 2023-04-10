##Cesar's Cypher 1.1

Cesar cypher is a cypher that encodes and decodes text and digits with the 
Cesar's algorithm of encriptation. The algorithm original form of Cesar's algorithm 
is aply a shift, defined as key, to each letter of the message.

A better way to encrypt a message by the same algorithm is use a rotary cypher, that is
the key is new for every new letter. This way, in the last example the key would be 12
on the first letter, and 13 for the second one and so on.
We can use any integer as a key, but the value will be 'moduled' for the 26 letter on the alphabet
and the 10 digits. So in the practice it have only 26 discrete keys possyble.

If we encode the same "HELLO WORLD" on rotary mode on '-r' we get "TRZAE OHLGZ".

Cesar's Cypher no longer acept input from stdin, but if no output file is provided it will
outut on the stdout.

Now the cypher acepts a string of options for example -rd

#options
-r - set rotary mode
-d - set decypher mode
-i <file> - set the input file
-o <file> - set the output file
-k <key> - set the key

the input file and key options are mandatory
