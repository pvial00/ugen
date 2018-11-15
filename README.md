# ugen

ugen is a uniform password string genertor.  It generates passwords using A-Z, a-z, 0-9, and OWASP special characters to create the most secure and uniformly distributed passwords.

https://www.owasp.org/index.php/Password_special_characters

ugen's core is /dev/urandom.  /dev/urandom is sampled until the password length is reached.

ugen will generate up to 1 Megabyte password strings and as little as 1.
