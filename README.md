##Cesar's Cypher 1.0

Cesar cypher is a cypher that encodes and decodes text and digits with the 
Cesar's algorithm of encriptation. The algorithm original form of Cesar's algorithm 
is aply a shift, defined as key, to each letter of the message.

Example, if we apply the shift 12 on "HELLO WORLD" we get "TQXXA IADXP"
because H + 12 --> T,

A better way to encrypt a message by the same algorithm is use a rotary cypher, that is
the key is new for every new letter. This way, in the last example the key would be 12
on the first letter, and 13 for the second one and so on.
We can use any integer as a key, but the value will be 'moduled' for the 26 letter on the alphabet
and the 10 digits. So in the practice it have only 26 discrete keys possyble.

If we encode the same "HELLO WORLD" on rotary mode on '-r' we get "TRZAE OHLGZ".


###Options
- '-r' - Set rotary Mode
- '-d' - Set Decrypt Mode
- '-i' - Define input file
- '-o' - Define output file
- '-k' - Define Key
