function w = somlearn(w, u, x, mu_i, mu_f, sigma_i, sigma_f, t, tmax)
x_pick = pickrand(x);
i = index_of_closest(x_pick, w);
w = update_weights(w, u, x_pick, i, t, tmax, mu_i, mu_f, sigma_i, sigma_f);
end