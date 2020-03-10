# 103cipher_2019

## Description
Maths 103cipher Epitech Teck1

Cryptography is a very old science, whose goal is to secure communication, so that only its recipient could
read it.

There are a lot of methods to encrypt a message, from the simplest (such as the 2,000-year-old Caesar
cipher) to the most complex (such as the World War 2 Enigma code); they all need both encryption and
decryption keys (sometimes identical).

In some cases (such as the Hill cipher), the key is represented by a matrix.

You have to carry out such a matrix-based ciphering software, using the following process to encrypt :  
• Transcript the key into numbers using the ASCII table,  
• Convert the numbered key into a square matrix, the smallest possible size, and filling the lines first,  
• Transcript the clear message into numbers using the ASCII table,  
• Convert the numbered message into a matrix; its number of columns should fit the key matrix size,
and its number of lines should be as small as possible,  
• Multiply the 2 matrices, and write the answer linearly to get the encrypted message.  

#### USAGE
    ./103cipher message key flag

#### DESCRIPTION
| params   |  description                                           |
| -------- |:------------------------------------------------------:|
| message  |  a message, made of ASCII characteres                  |
| key      |  the encryption key, made of ASCII characters          |
| flag     |  0 for the message to be encrypted, 1 to be decrypted  |

## Result
93.5% moulinette Epitech
