/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:36:48 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/25 23:42:35 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int ac, char **av, char **envp)
{
    int i = 0;
    int status = 0;

    if (ac > 1)
    {
        while (av[i] && av[++i])
        {
            av += i;
            i = 0;
            while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
                i++;
            if (!strcmp(*av, "cd"))
                status = cd(av,i);
            else if (i)
                status = exec(av, envp, i);
        }
    }
    return (status);
}