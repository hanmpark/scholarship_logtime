require 'oauth2'
require 'scanf'
require 'uri'
require 'net/http'

UID = ENV['UID_42']
SECRET = ENV['SECRET_42']
# Create the client with your credentials
client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")
# Get an access token
token = client.client_credentials.get_token
login = scanf("%s")
File.open("dates.txt", "w") { |file| file.write token.get("/v2/users/%s/locations_stats" % login).parsed()}
uri = URI('https://calendrier.api.gouv.fr/jours-feries/metropole.json')
res = Net::HTTP.get_response(uri)
File.open("holidays.txt", "w") { |file| file.write(res.body)}
