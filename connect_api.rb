require "oauth2"
require 'scanf'

UID = "u-s4t2ud-181a564c1457683b23956b69e779751ff829412d7ed6d9cdcbbfa741899f2750"
SECRET = "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"
# Create the client with your credentials
client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")
# Get an access token
token = client.client_credentials.get_token
print("Login: ")
login = scanf("%s")
File.open("texts/text_file.txt", "w") { |file| file.write token.get("/v2/users/%s/locations_stats" % login).parsed()}
