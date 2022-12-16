# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.rb                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 23:47:09 by hanmpark          #+#    #+#              #
#    Updated: 2022/12/15 23:54:35 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

require "oauth2"
require 'scanf'

UID = ENV['UID_42']
SECRET = ENV['SECRET_42']
# Create the client with your credentials
client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")
# Get an access token
token = client.client_credentials.get_token
print("Login: ")
login = scanf("%s")
File.open("text_file.txt", "w") { |file| file.write token.get("/v2/users/%s/locations_stats" % login).parsed()}
