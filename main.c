/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:01:02 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/11 09:19:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curl/curl.h>

int	main(void)
{
	CURL		*curl;
	CURLcode	res;
	
	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (!curl)
		return (-1);

	curl_easy_setopt(curl, CURLOPT_URL, "https://profile.intra.42.fr/users/hanmpark/locations_stats/");
	res = curl_easy_perform(curl);
	if (res != CURLE_OK)
		fprintf(stderr, "curl easy_perform() returned %s\n", curl_easy_strerror(res));
	curl_easy_cleanup(curl);

	curl_global_cleanup();
	return (0);
}
