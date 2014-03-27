/***
 * Excerpted from "Arduino: A Quick-Start Guide",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/msard for more book information.
***/
#ifndef __SMTP_SERVICE__H_
#define __SMTP_SERVICE__H_

#include <SPI.h>
#include <Ethernet.h>
#include "email.h"

class SmtpService {
  IPAddress    _smtp_server;
  unsigned int _port;
 
  void read_response(EthernetClient& client) { 
    delay(4000);
    while (client.available()) {
      const char c = client.read();
      Serial.print(c);
    }
  }

  void send_line(EthernetClient& client, String line) { 
    const unsigned int MAX_LINE = 256;
    char buffer[MAX_LINE];
    line.toCharArray(buffer, MAX_LINE);
    Serial.println(buffer);
    client.println(buffer);
    read_response(client);
  }

  public:
  
  SmtpService( 
    const IPAddress&   smtp_server,
    const unsigned int port) : _smtp_server(smtp_server), 
                               _port(port) {}
                               
  void send_email(const Email& email) { 
    EthernetClient client;
    Serial.print("Connecting...");
  
    if (client.connect(_smtp_server, _port) <= 0) {
      Serial.println("connection failed.");
    } else {
      Serial.println("connected.");
      read_response(client);
      send_line(client, String("helo"));
      send_line(
        client,
        String("mail from: <") + email.getFrom() + String(">")
      );
      send_line(
        client,
        String("rcpt to: <") + email.getTo() + String(">")
      );
      send_line(client, String("data"));
      send_line(client, String("from: ") + email.getFrom());
      send_line(client, String("to: ") + email.getTo());
      send_line(client, String("subject: ") + email.getSubject());
      send_line(client, String(""));
      send_line(client, email.getBody());
      send_line(client, String("."));    
      send_line(client, String("quit"));    
      client.println("Disconnecting.");
      client.stop();
    }
  }
};

#endif
