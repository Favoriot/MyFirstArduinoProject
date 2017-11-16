/* This code is only for sending your data to the favoriot platform .
 * Please note that this is an incomplete code.
 * PLease include this code along with your Arduino program and the wifi codes.
 */

String apikey = "Your API key";    // replace with your api key from the FAVORIOT platform account setting
char serverAdd[] = "api.favoriot.com";
datatype yourData = “ “ ;

void loop() {
{
   dataStream();
}

void dataStream()
{ 
  // Json Data to send to Platform
  String json = "{\"device_developer_id\":\"insert your device_id from FAVORIOT platform here \",\"data\":{\"Data\":\""+String(yourData)+"\"}}";
  
  if (client.connect(serverAdd, 80)) {
    // Make a HTTP request:
    client.println("POST /v1/streams HTTP/1.1");
    client.println("Host: api.favoriot.com");
    client.print(String("apikey: "));
    client.println(apikey);
    client.println("Content-Type: application/json");
    client.println("cache-control: no-cache");
    client.print("Content-Length: ");
    int thisLength = json.length();
    client.println(thisLength);
    client.println("Connection: close");

    client.println();
    client.println(json);
    }
}

