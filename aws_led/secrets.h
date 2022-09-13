#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "ESP32_LED"                         //change this
 
const char WIFI_SSID[] = "aliyu";               //change this
const char WIFI_PASSWORD[] = "******##";           //change this
const char AWS_IOT_ENDPOINT[] = "a1vgoyp22ws2f7-ats.iot.us-east-1.amazonaws.com";       //change this
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVALx0qGMqsjZgH6WESIIgyS3QICS6MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjA5MDQxODI0
MDVaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDNk9XCUWDGZadm2Ikr
GIYwf5QG2XR+gmMnn79LOyvabFnmdD1FXkZPY5bwqpHp8kUeR46HoHfB6ceoWiH9
6t2XVqNQispAMfsGyQXnS61A8968R/LG+jUWTqgmtHEb5nzPxZ8J4VyLirA6ET3I
8CWQVy3zOCmGfEhW8NZPa0ujSqmqTBy/qRNJJfdM3RAtgvjSFyi1OaXOqVVjhpqZ
pR69YJE5tHfCvtR6gf5ofTy3gIOR4yHFAjGzfoCr1N2Aed9vWk0vAvLPQvxkXxPL
P+8vX8KB08l+rwKG4RHvzNz5vBIqOIOMOJHdNYsrlT+iQgEa+Y/cKSK8bDgntHmb
AGv1AgMBAAGjYDBeMB8GA1UdIwQYMBaAFGo+fd1wQvCwdtjrGjWqOeuATv4uMB0G
A1UdDgQWBBTHZIu7phqk31AenJIZ3FjPe4v63DAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAgdMngguf79AOgP3pAUQBTS3o
SpmdMaAmw6lZAMMSmzDWR2qraWNZdB3MmoYztZavTlM3OaSn5MsL8vi7NM0g5Fts
2r6e+wm61wyoS+XtmoqKCrBZXLW4jXd4zZQVKrs08zfDWrV9lSMf01qtXFB3objj
J/1NFa10/QBo2Z1uxR2fDae50HLCXYlqxJrd1itgQvUsfQhyfnx4ccdyEyXpbpHN
cViR/eO0lR9kycddmWkst7+mDqFRXnCti3hT09i+cUQbolqbbBQ3jrIeCIPZFcl0
Hlh1+hEmfsvH7ItyZ7DnIOerXoGFdT+YG0z9NVVgtsqFyMjyWaWkZkOP9n1nCQ==
-----END CERTIFICATE-----

 
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAzZPVwlFgxmWnZtiJKxiGMH+UBtl0foJjJ5+/Szsr2mxZ5nQ9
RV5GT2OW8KqR6fJFHkeOh6B3wenHqFoh/erdl1ajUIrKQDH7BskF50utQPPevEfy
xvo1Fk6oJrRxG+Z8z8WfCeFci4qwOhE9yPAlkFct8zgphnxIVvDWT2tLo0qpqkwc
v6kTSSX3TN0QLYL40hcotTmlzqlVY4aamaUevWCRObR3wr7UeoH+aH08t4CDkeMh
xQIxs36Aq9TdgHnfb1pNLwLyz0L8ZF8Tyz/vL1/CgdPJfq8ChuER78zc+bwSKjiD
jDiR3TWLK5U/okIBGvmP3CkivGw4J7R5mwBr9QIDAQABAoIBADMK0bg9nFmmQ7o1
aVlZ7Xd9NbO9qj7/AL+F2mlDd8/ztx6RHeVrUunDQGbg8vmzPZYXDjx+iz2KXhhe
yLHS7tH0oPgOfckSn9E/eEfFcm7+Hf+BnbXpyeSQAxAZHTxgLf0ohCRf4CqFdNv2
C/EoLyt3eeE5wJWzpgJwKcXuTglsvkDOTlAuGSdzjVoFvvGK6lLf3HKFlbDnG52R
uENRmdbaPNOBDWjPvKlVs1z+5cUwm5JfnHKzcRaQtq651SJ5yfeKLoDTbVdMSWSo
A2P9sAlxF9C6zt3/Mfv4rPlFvibk7xe4EEmuSrBVDYaVU684T0U9VXkZtno7WXh0
q1lOugECgYEA8aPJV2JnwZQNb2iUlHL0Z3aKsrcspIbfm8GNeb5iEgRM4TmkzJQe
si2ITbuZgOuMfwv0WkvBJeR61mzoOPzmnjH8QzpsEJl4Itu+OqCugFVY0ctAE4ri
2RJyuX3/qq3SaEaIRViaGf471C+oYJDFNOU+DO9+M2vzhjNAwM1omtkCgYEA2ctp
G/rjiD5V4Ag7AEVaBfBoOUpKS7AM/UWiMWQK9e9iaxB02Jahjua9VEBcxIroraHz
E7Vqxaw/niwJh5/I7WVTXx2W6ZfP349nE+FM5s9v41fjgzfK51QLBts61HUlep5a
R71VJhVZ5+L1xZKu6fOVVUMFTyhrS7JHW/MxUH0CgYEA3crSMa0XQy0br9i0GBXz
k0vRPvy2s0VA1Xww2UAQUC02S7xXMZf7HNyCMacx3I1X5f0ZChBidt9iiJJqDHTF
UQrcWvCy5AGZrZU45CM8SHsODXKbm9RtJ4WxW+T02Lq3WBL1XYFX4OfkDny39fqr
qEOKUuE4WwaI/fLpSo6/pvECgYAE3X5jmZ8rk/jnIEfxIZt5Nn2digNO3YfswHl3
EP0NsWNJcPyrOfIx9wWTtDxeR5wbBNshPZQ9BjQFnIY5+V/Lrc/G+Co+3Z1PKSzs
TMQjA89EDNqQO9bUhBQa+xq9VECaFJ9/qsMULrXrcC59U2GE6GQVm4Gq2wRKlJjz
fONFIQKBgFP9M/M5ljzf3r+1f9EQLoJv7scCn8hbRs8k4bVyOFNHZ5XqDRQXlZSa
ERhl0KjtF8EJph5qlemYFJb3Vezf1o1nqWN4Y6Mxn4ZtX9OnMHWZunn0ArWQf86j
NI8pgsCeXuVeEINjNH7SX5F2Ksn2xx86piQd5SNnCPaoJ401jgFw
-----END RSA PRIVATE KEY-----

-----END RSA PRIVATE KEY-----
 
)KEY";