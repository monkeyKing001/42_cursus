/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:06:26 by mjung             #+#    #+#             */
/*   Updated: 2021/11/03 21:06:29 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
/*
	<megaphone>
	입력받은 값을 대문자로 변경해서 출력해주는 프로그램
	- 입력받는 인자값은 여러개인 경우 모두 이어서 출력해줌
	- 인자값이 없는 경우 아래 내용 출력
		* LOUD AND UNBEARABLE FEEDBACK NOISE * 
*/

int main(int argc, char **argv)
{
	if (argc <= 1)
	// 인자값이 없는 경우
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int idx = 1; idx < argc; idx++)
		{
			std::string str = argv[idx];
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return (0);
}
